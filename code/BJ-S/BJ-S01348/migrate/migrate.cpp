#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long x[500010],dis[500010],cnt[500010],d;
void dij(int s)
{
    queue<int> q;
    q.push(s);
    cnt[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int step=q.front();
        q.pop();
        int pos=upper_bound(x+1,x+n+1,x[step]+d)-x-1;
        for(int i=pos;i>step;i--)
        {
            if(dis[i]<=dis[step]) break;
            if(dis[i]>dis[step]+1)
            {
                dis[i]=dis[step]+1;
                cnt[i]=cnt[step];
                q.push(i);
            }
            else if(dis[i]==dis[step]+1) cnt[i]+=cnt[step];
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[j]=1e9;
                cnt[j]=0;
            }
            dij(i);
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
