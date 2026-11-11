#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long co,t,n,d;
long long x[N];
long long di[N];
vector<long long> c[1000];
long long dis[1000][1000];
long long cnt[1000][1000];
bool vis[N];
void dfs(long long st,long long now,long long nd)
{
    if(nd<dis[st][now])dis[st][now]=nd;
    if(nd==dis[st][now])cnt[st][now]++;
    vis[now]=1;
    for(int i:c[now])
    {
        if(vis[i])continue;
        dfs(st,i,nd+1);
    }
    vis[now]=0;
    return;
}
int main()
{

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>co>>t;
    for(int I=0;I<t;I++)
    {
        memset(dis,0x3f,sizeof(dis));
        memset(cnt,0x3f,sizeof(cnt));
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(i>=2)di[i]=x[i]-x[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            long long sum=0;
            for(int j=i+1;sum+di[j]<=d;j++){
                c[i].push_back(j);
                sum+=di[j];
            }
            sum=0;
            for(int j=i-1;sum+di[j+1]<=d;j--){
                c[i].push_back(j);
                sum+=di[j+1];
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            dfs(i,i,0);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cnt[i][j]==3)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
