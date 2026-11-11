#include<bits/stdc++.h>
using namespace std;
int d[200005],mx=INT_MIN,cc,m;
int n;
long long ans;
void dfs(int step,int num,long long cnt)
{
    if(step==0)cnt=num;
    if(step==m)
    {
        ans=max(ans,cnt);
        return;
    }
    for(int i = num+1;i < n;i++)
    {
        dfs(step+1,i,cnt&d[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
cin>>n>>m;
if(m==1)
{
    for(int i = 0;i < n;i++)
    {
        cin>>d[i];
        mx=max(mx,d[i]);
    }
    cout<<mx;
    return 0;
}
if(m==n)
{
    cin>>d[0];
    cc=d[0];
    for(int i = 1;i < n;i++)
    {
        cin>>d[i];
        cc&=d[i];
    }
    cout<<cc;
    return 0;
}
if(m==2)
{
    for(int i = 1;i < n;i++)cin>>d[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(j!=i)
            {
                mx=max(mx,d[i]&d[j]);
            }
        }
    }
    cout<<mx;
    return 0;
}
if(m==n-1)
{
    for(int i = 1;i < n;i++)cin>>d[i];
    for(int i = 0;i < n;i++)
    {
        mx=0;
        for(int j = 0;j < n;j++)
        {
            if(j!=i)
            {
                mx&=d[j];
            }
        }
        mx&=0;
        cc=max(cc,mx);
    }
    cout<<cc;
    return 0;
}
for(int i = 0;i < n;i++)
{
        cin>>d[i];
}
for(int i =0;i < n;i++)
{
    dfs(0,i,0);
}
cout<<ans;
return 0;
}
