#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int n,d;
int f[2000005];
int g[2000005];
int p[2000005];
int q[2000005];
int dis[2000005];
int cnt[2000005];
int check(int l,int r)
{
    for(int i = l; i <= r; i++) dis[i] = 1e18,cnt[i] = 0;
    dis[l] = 0,cnt[l] = 1;
    for(int i = l; i <= r; i++)
    {
        for(int j = i + 1; j <= r; j++)
        {
            if(a[j] - a[i] > d) break;
            if(dis[j] == dis[i] + 1) cnt[j] += cnt[i];
            else if(dis[j] > dis[i] + 1) dis[j] = dis[i] + 1,cnt[j] = cnt[i];
        }
    }
    return cnt[r];
}
void work()
{
    cin >> n >> d;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        check(i,n);
        for(int j = i; j <= n; j++)
            if(cnt[j] == 2)
                ans++;
    }
    cout << ans <<'\n';
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--) work();
}
