#include<bits/stdc++.h>
using namespace std;
bool k[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]) k[0]=1;
    if(k[0]==1 && s1[0]==s2[0] && s1[1]==s2[1]) k[1]=1;
    int n,m;
    if(k[1]==0) k[2]=0;
    else
    {
        n=s1[2]-'A';
        m=s2[2]-'A';
        int u1,u2;
        if(n>=4) u1=2;
        else u1=1;
        if(m>=4) u2=2;
        else u2=1;
        if(u1==u2) k[2]=1;
        else k[2]=0;
    }
    if(k[2]==1)
    {
        if(n-m==1) k[3]=1;
        else if(m-n==1) k[3]=1;
        else k[3]=0;
    }
    for(int i=0;i<=3;i++)
    {
        cout<<k[i];
    }
    return 0;
}
