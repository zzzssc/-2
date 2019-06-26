//
//  main.cpp
//  文件传输2
//
//  Created by s20181106119 on 2019/6/26.
//  Copyright © 2019 s20181106119. All rights reserved.
//

#include<iostream>
#include<fstream>
using namespace std;
struct student{
    char name1[50];       //学生姓名
    int  number[50];      //学号
    char  colleage[50];   //学院
    char  speciality[50];   //专业
    char name2[8];    //裁判姓名
    int score[7]={0};    //分数
    double ave[7];
};
int main()
{
    int y;
    struct student x[y];
    ifstream in("Users/s20181106119/Desktop/学生信息.txt");
    ifstream inf ("Users/s20181106119/Desktop/裁判信息及分数.txt");
    {
        
        int i,l;
        for(i=1;i<50;i++)
        {
            for(l=1;l<8;l++)
            {
                in>>x[i].score[l]>>x[i].colleage[l]>>x[i].speciality[l];
            }
            
        }
        in.close();
        inf.close();
    }
     ofstream output("Users/s20181106119/Desktop/最终排名.txt");
    {
    
        int i,l,sum=0,a=0;
        
        for(i=1;i<50;i++)
        {
            for(l=1;l<8;l++)
            {
                sum=sum+x[i].score[l];
            }
            x[i].ave[i]=sum/l;
        }
        for(i=1;i<50;i++)
        {
            for(l=1;l<8;l++)
            {
                if(a<x[i].ave[i])
                {
                    a=x[i].ave[i];
                    x[i].ave[i]=x[i+1].ave[i+1];
                    x[i+1].ave[i+1]=a;
                }
            }
        }
        for(i=1;i<50;i++)
        {
            for(l=1;l<8;l++)
            {
                output<<x[i].name1[l]<<x[i].ave[i];
            }
        }
   
    }
        return 0;
    }

