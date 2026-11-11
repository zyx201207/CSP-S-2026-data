#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long inf = 1e18;
const long long mod = 998244353;
const long long N = 2e6 + 5;
int n , m;
int dis[N];
int cnt[N];
int x[N];
int d;
bitset<N>vis;
int ttime[N];
int ccnt = 0;
int bfs(int S)
{
    int res = 0;
    dis[S] = 0 , cnt[S] = 1;
    /*
    for(int i = S + 1 ; i <= n ; i++)
    {
        if(dis[i] == inf)break;
        dis[i] = inf , cnt[i] = 0 , vis[i] = 0;
    }
    */
    queue<int>q;
    q.push(S);
    int u;
    while(!q.empty()){
        u = q.front() , q.pop();
        for(int v = u + 1 ; v <= n && x[v] - x[u] <= d ; v++)
        {
            if(ttime[v] < ccnt)dis[v] = inf , cnt[v] = 0 , vis[v] = 0 , ttime[v] = ccnt;
            if(dis[v] > dis[u] + 1)
            {
                if(dis[v] == inf)q.push(v);
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                if(cnt[u] <= 2)vis[v] = 0;
                else vis[v] = 1;
            }
            else if(dis[v] == dis[u] + 1)cnt[v] += cnt[u];
        }
    }
    for(int i = S ; i <= n ; i++)if(cnt[i] == 2)res++;
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int __ , ___;
    cin >> __ >> ___;
    while(___--)
    {
        int cnt = 0 ; bool flag = 1;
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++)cin >> x[i];
        for(int i = 2 ; i <= n ; i++)flag &= (x[i] - x[i - 1] == x[2] - x[1]);
        if(flag)
        {
            int kk = d / (x[2] - x[1]);
            if(kk <= 1)
            {
                cout << 0 << endl;
                continue;
            }
            cout << max(n - (2 * kk - 1) , 0ll) << endl;
            continue;
        }
        /*
        if(13 <= __ && __ <= 14)
        {
            cout << 0 << endl;
            continue;
        }
        */
        sort(x + 1 , x + 1 + n , less<int>());
        int ans = 0;
        for(int i = 1 ; i < n ; i++)++ccnt , ans += bfs(i);
        cout << ans << endl;
    }

    return 0;
}
