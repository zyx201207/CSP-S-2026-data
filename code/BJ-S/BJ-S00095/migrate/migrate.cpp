#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5001],dist,total=1;
bool flag[5001];
void dfs(long long now,long long last,long long dis,bool flag[])
{
    if(now==last)
    {
        if(dist==dis)
        {
            total++;
        }
        else if(dist>dis)
        {
            total=1;
            dist=dis;
        }
        return ;
    }
    if(dis>dist)
    {
        return ;
    }
    for(long long v=1;v<=last;v++)
    {
        if(abs(x[v]-x[now])<=d&&flag[v]==true)
        {
            flag[v]=false;
            dfs(v,last,dis+1,flag);
            flag[v]=true;
        }
        else if(abs(x[v]-x[now])>d)
        {
            break;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(int i=1;i<=5000;i++)
    {
        flag[i]=true;
    }
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(long long j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        long long ans=0;
        for(long long a=1;a<=n;a++)
        {
            for(long long b=a+1;b<=n;b++)
            {
                total=0;
                dist=100001;
                flag[a]=false;
                dfs(a,b,0,flag);
                flag[a]=true;
                for(int l=1;l<=n;l++)
                {
                    flag[l]=true;
                }
                if(total==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}