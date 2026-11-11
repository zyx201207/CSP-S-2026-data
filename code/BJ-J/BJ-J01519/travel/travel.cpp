#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int ans[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1.size()!=c2.size())ans[0]=0;
    else
    {
        int flag=1;
        for(int i=0;i<=c1.size()-1;i++)if(c1[i]!=c2[i])flag=0;
        if(flag==1)ans[0]=1;
        else ans[0]=0;
    }
    if(ans[0]==1)
    {
        string t1=s1,t2=s2;
        if(t1.size()!=t2.size())ans[1]=0;
        else
        {
            int flag=1;
            for(int i=0;i<=t1.size()-2;i++)
                if(t1[i]!=t2[i])flag=0;
            if(flag==0)ans[1]=0;
            else ans[1]=1;
        }
    }
    else ans[1]=0;
    if(ans[1]==1)
    {
        int n=s1.size()-1;
        if(s1[n]>='A'&&s1[n]<='C'&&s2[n]>='D')ans[2]=0;
        else if(s1[n]>='D'&&s2[n]<='C')ans[2]=0;
        else ans[2]=1;
    }
    else ans[2]=0;
    if(ans[2]==1)
    {
        int n=s1.size()-1;
        if(s1[n]==(s2[n]+1)||s1[n]==(s2[n]-1))ans[3]=1;
        else ans[3]=0;
    }
    else ans[3]=0;
    cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
    return 0;
}