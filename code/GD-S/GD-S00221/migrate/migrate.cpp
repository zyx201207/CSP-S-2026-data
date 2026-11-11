#include<iostream>
#include<limits>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll res=0;
        auto Dijkstra=[&](const int start)
        {
            vector<ll> dist(n+1,numeric_limits<ll>::max());
            vector<int> cnt(n+1);
            queue<pair<int,ll>> q;
            dist[start]=0;
            cnt[start]=1;
            q.push(make_pair(start,0));
            while(!q.empty())
            {
                const int from=q.front().first;
                const ll distance=q.front().second;
                q.pop();
                if(distance>dist[from])
                {
                    continue;
                }
                else
                {
                    for(int to=from+1;to<=n&&a[to]-a[from]<=d;to++)
                    {
                        if(dist[to]>distance+1)
                        {
                            dist[to]=distance+1;
                            cnt[to]=cnt[from];
                            q.push(make_pair(to,dist[to]));
                        }
                        else if(dist[to]==distance+1)
                        {
                            cnt[to]+=cnt[from];
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(cnt[i]==2)
                {
                    res++;
                }
            }
        };
        for(int i=1;i<=n;i++)
        {
            Dijkstra(i);
        }
        cout<<res<<'\n';
    }
}
