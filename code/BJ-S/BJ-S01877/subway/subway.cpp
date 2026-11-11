#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 500,M = 5e5;
int d[N + 5][N + 5];
int sz[M + 5];
vector<pair<int,int> > a[M + 5];
int w[M + 5];
int c,n,m,D,q;

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> D >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            int t1,t2;
            cin >> t1 >> t2;
            a[t1].push_back({i,t2});
        }
    }/*
    for(int i = 1;i <= m;i++)
    {
        cout << i << ' ' << a[i].size() << ":";
        for(int j = 0;j < a[i].size();j++)
        {
            cout << a[i][j].first << ' ' << a[i][j].second << endl;
        }
    }*/
    memset(d,0x3f,sizeof(d));
    for(int i = 1;i <= m;i++)
    {
        sz[i] = a[i].size();
        for(int j = 0;j < sz[i];j++)
        {
            for(int k = j + 1;k < sz[i];k++)
            {
                int p1 = a[i][j].first,d1 = a[i][j].second,p2 = a[i][k].first,d2 = a[i][k].second;
                //cout << i << ' ' << p1 << ' ' << d1 << ' ' <<p2 << ' ' << d2 << endl;
                d[p1][p2] = min(d[p1][p2],d1 + d2);
                d[p2][p1] = min(d[p2][p1],d1 + d2);
            }
        }
    }
    for(int i = 1;i <= n;i++) d[i][i] = 0;/*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }*/
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                d[j][i] = d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
    /*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }*/
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        int ans = 9e18;
        for(int i = 0;i < sz[u];i++)
        {
            for(int j = 0;j < sz[v];j++)
            {
                ans = min(ans,a[u][i].second + a[v][j].second + d[a[u][i].first][a[v][j].first]);
            }
        }
        ans += w[u] + w[v];
        cout << ans << endl;
    }
	return 0;
}
