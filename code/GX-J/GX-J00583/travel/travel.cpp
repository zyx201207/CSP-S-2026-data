#include<bits/stdc++.h>
using namespace std;
int num1,num2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    struct{
        char c1;
        string s1;
    }a;
    struct{
        char c2;
        string s2;
    }b;
    cin>>a.c1>>a.s1>>b.c2>>b.s2;
    string sum1=a.s1,sum2=b.s2;
    bool n,m;
    bool x,y;
    if(a.c1==b.c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    for(int i=1;i<=sum1.size();i++)
    {
        if(i==3)
        {
            char ove1=i;
            if(ove1=='A'||ove1=='B'||ove1=='C')
            {
                n=true;
                x=true;
            }
            else if(ove1=='D'||ove1=='F')
            {
                n=true;
                x=false;
            }
            else
            {
                n=false;
            }
        }
    }
    for(int j=1;j<=sum2.size();j++)
    {
        if(j==3)
        {
            char ove2=j;
            if(ove2=='A'||ove2=='B'||ove2=='C')
            {
                m=true;
                y=true;
            }
            else if(ove2=='D'||ove2=='F')
            {
                m=true;
            }
            else
            {
                m=false;
                y=false;
            }
        }
    }
    if(sum1[1]==sum2[1]&&sum1[2]==sum2[2])
    {
        cout<<'1';

    }
    else
    {
        cout<<'0';
    }
    if(n==true && m==true)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    if(x==true&&y==true)
    {
        if(sum1[3]=='A'&&sum2[3]=='C')
        {
            cout<<'0';
        }
        else
        {
            cout<<'1';
            return 0;
        }
    }
    if(x==false&&y==false)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    return 0;

}
