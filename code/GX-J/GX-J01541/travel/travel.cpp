#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum,s,g,flag,son;
char h;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++)
    {
        g=(c1[i]-'0')%10;
        s=(c1[i]-'0')/10;
    }
    for(int i=0;i<c2.size();i++)
    {
      if(g==(c2[i]-'0')%10 && s==(c2[i]-'0')/10)
      {
          sum=sum+1;
      }
    }
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]-'0'>=0 && s1[i]-'0'<=9)
        {
            flag=flag+s1[i]-'0';
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]-'0'>=0 && s2[i]-'0'<=9)
        {
            son=son+s1[i]-'0';
        }
    }
    if(flag==son)
    {
        sum=sum*10+1;
    }
    else
    {
        sum=sum*10;
    }
    for(int i=0;i<s1.size();i++)
    {
        h=s1[i];
        if(h-'A'>=0 && h-'A'<=7)
        {
            flag=s1[i]-'A';
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]-'A'>=0 && s2[i]-'A'<=7)
        {
            son=s2[i]-'A';
        }
    }
    if(flag+son<=3 || flag+son==10)
    {
        sum=sum*10+1;
    }
    else
    {
        sum=sum*10;
    }
    if(abs(flag-son)==1)
    {
        sum=sum*10+1;
    }
    else
    {
        sum=sum*10;
    }
    cout<<sum;
    return 0;
}
