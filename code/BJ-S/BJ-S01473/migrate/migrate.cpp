#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,d,ans=0;
pair<long long,long long> dfs(long long i,long long zd)
{
    if(i==zd)
    {
        return {0,1};
    }
    long long minn=LLONG_MAX-20,cnt=0;
    for(int j=i+1;j<=n;j++)
    {
        if(a[j]-a[i]>d)
        {
            return {minn,cnt};
        }
        pair<long long,long long> k=dfs(j,zd);
        k.first++;
        if(k.first<minn)
        {
            minn=k.first;
            cnt=k.second;
        }
        else if(k.first==minn)
        {
        cnt+=k.second;
        }


    }return {minn,cnt};
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
cin>>c>>t;
    if(c==13||c==14)
    {
while(t--)
{
cin>>n>>d;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
if((a[j]-a[i])>c)
{
  ans++;
}
    }
}
cout<<ans<<endl;
ans=0;
}
}else{
        while(t--)
{

cin>>n>>d;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
if(dfs(i,j).second==2)
{
    ans++;
}
    }
}
cout<<ans<<endl;
ans=0;
}
    }}
