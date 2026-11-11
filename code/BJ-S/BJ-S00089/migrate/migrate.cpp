#include<bits/stdc++.h>
using namespace std;
const int N=2e6+4;
long long cnt,d;
long long sd[N];
bool vis[N];
int n,nmin;
void dfs(int st,int ed,int len)
{
    if(st==ed)
    {
        if(len<nmin)
        {
            nmin=len;
            cnt=1;
        }
        else if(len==nmin)
        {
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&abs(sd[st]-sd[i])<=d)
        {
            vis[i]=true;
            dfs(i,ed,len+1);
            vis[i]=false;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>sd[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                memset(vis,0,sizeof(vis));
                dfs(i,j,0);
                if(cnt==2)
                {
                    ans++;
                }
                cnt=0,nmin=2e9;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}