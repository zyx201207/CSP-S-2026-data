#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6+5;
ll a[N];
int maxx[N];
int dis[N];
int q[N];
int cnt[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int _ = 1;_<=t;++_)
    {
        int n;
        ll d;
        cin >> n >> d;
        for(int i = 1;i<=n;++i)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        for(int i = 1,j = 1;i<=n;++i)
        {
            while(j<=n&&a[j]-a[i]<=d)
            {
                ++j;
            }
            --j;
            maxx[i] = j;
        }
        ll ans = 0;
        for(int i = 1;i<=n;++i)
        {
            int h = 1,t = 0;
            q[++t] = i;
            for(int j = 1;j<=n;++j)
            {
                dis[j] = 1e9;
                cnt[j] = 0;
            }
            dis[i] = 0;
            cnt[i] = 1;
            while(h<=t)
            {
                int x = q[h];
                ++h;
                for(int v = 1;v<=maxx[x];++v)
                {
                    int s = dis[x]+1;
                    if(dis[v]>s)
                    {
                        cnt[v] = cnt[x];
                        if(cnt[v]>2)
                        {
                            continue;
                        }
                        dis[v] = s;
                        q[++t] = v;
                    }
                    else if(dis[v] == s)
                    {
                        cnt[v]+=cnt[x];
                        if(cnt[v]>2)
                        {
                            continue;
                        }
                    }
                }
            }
            for(int j = 1;j<=n;++j)
            {
                if(cnt[j] == 2)
                {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}