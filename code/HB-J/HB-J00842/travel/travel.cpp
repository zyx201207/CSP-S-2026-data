#include<bits/stdc++.h>
int MAXN=100+5;
using namespace std;
int main()
{
    freopen(char travel,travel.in,stdin);
    freopen(char travel,travel.out,stdout);
    string a[MAXN];
    int n[MAXN];
    cin>>a[MAXN];
    int l=4;
    string c1=a[0];
    string s1=a[1];
    string c2=a[2];
    string s2=a[3];
    if(c1==c2)
    {
        n[0]=1;
        if(s1[1]!=s2[1])
        {
            for(int i=1;i<l;i++)
            {
                n[i]=0;
            }
        }
        if(s1[1]==s2[1])
        {
            n[1]=1;
            if(s1[2]=='C'&&s2[2]=='D')
            {
                n[2]=0;
                n[3]=0;
            }
            if(s1[2]=='D'&&s2[2]=='C')
            {
                n[2]=0;
                n[3]=0;
            }
            if(s1[2]<='C'&&s2[2]<='C')
            {
                n[2]=1;
                if(s1[2]>s2[2]&&s1[2]-s2[2]=='2'-'1')
                {
                    n[3]=1;
                }
                if(s1[2]<s2[2]&&s2[2]-s1[2]=='2'-'1')
                {
                    n[3]=1;
                }
            if(s1[2]>'C'&&s2[2]>'C')
            {
                n[2]=1;
                if(s1[2]>s2[2]&&s1[2]-s2[2]=='2'-'1')
                {
                    n[3]=1;
                }
                if(s1[2]<s2[2]&&s2[2]-s1[2]=='2'-'1')
                {
                    n[3]=1;
                }
            }
            }
        }
    }
    if(c1!=c2)
    {
        for(int i=0;i<l;i++)
        {
            n[i]=0;
        }
    }
    cout<<n[0]<<n[1]<<n[2]<<n[3];
    return 0;
}
