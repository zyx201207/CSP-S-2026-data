#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c; ++a)
using namespace std;
int a[2000005],dis[2000005];
int n,d,cnt[2000005];
void dfs(int x)
{
    cnt[x]++;
    // if (cnt[x]>2) return;
    lop(y,x+1,n)
    {
        if (a[y]-a[x]>d) return;
        if (dis[y]>=dis[x]+1)
        {
            dis[y]=dis[x]+1;
            dfs(y);
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int id,T;
    cin >> id >> T;
    // if (id==11||id==12)
    // {
    //     while (T--)
    //     {
    //         cin >> n >> d;
    //         loop(i,n) cin >> a[i];
    //         if (a[2]-a[1])
    //     }
    //     return 0;
    // }
    while (T--)
    {
        cin >> n >> d;
        loop(i,n)
        {
            cin >> a[i];
        }
        int ans=0;
        loop(i,n)
        {
            lop(j,i,n) dis[j]=LONG_LONG_MAX;
            dis[i]=0;
            dfs(i);
            lop(j,i,n) cnt[j]=0;
            dfs(i);
            lop(j,i+1,n)
            {
                if (cnt[j]==2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
