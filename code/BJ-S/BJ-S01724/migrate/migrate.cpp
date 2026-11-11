#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int f[10005], cnt[10005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin >> c;
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        long long k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int ls = i;
            f[i] = 0;
            memset(cnt, 0, sizeof(cnt));
            cnt[i] = 1;
            for(int j = i + 1;j <= n;j++)
            {
                while(a[j] > a[ls] + k) ls++;
                f[j] = f[ls] + 1;
                int tem = ls;
                while(f[ls] == f[tem])
                {
                    cnt[j] += cnt[tem];
                    tem++;
                }
            }
            for(int j = i + 1;j <= n;j++)
            {
                if(cnt[j] == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
