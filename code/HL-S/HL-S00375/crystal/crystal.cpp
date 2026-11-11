#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
int n,head,tot;
ll a[maxn],m,cnt,ans,b[maxn],num[maxn],k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    b[++tot]=a[1];
    num[tot]++;
    for (int i = 2;i <= n;i++)
    {
        if (a[i]==a[i-1])
        {
            num[tot]++;
        }
        else
        {
            b[++tot]=a[i];
            num[tot]=1;
        }
    }
    cnt=num[1];
    k = 0;
    ans = max(ans,cnt);
    head = 1;
    for (int i = 2;i <= tot;i++)
    {
        k += cnt * (b[i]-b[i-1]);
        cnt += num[i];
        if (k <= m)
        {
            ans = max(ans,cnt);
        }
        else
        {
            while(k - (b[i] - b[head])*num[head]>m)
            {
                cnt -= num[head];
                k-=(b[i]-b[head])*num[head];
                num[head]=0;
                head++;
            }
            if (k <= m)
            {
                ans = max(ans,cnt);
            }
            else
            {
                int gs = (k-m)/(b[i]-b[head]);
                int mod1 = (k-m)%(b[i]-b[head]);
                if (mod1 != 0)
                {
                    gs++;
                }
                k -= gs * (b[i]-b[head]);
                cnt -= gs;
                num[head]-=gs;
                if (num[head]==0)
                {
                    head++;
                }
                ans = max(ans,cnt);
            }
        }
    }
    cout << ans;
    return 0;
}
