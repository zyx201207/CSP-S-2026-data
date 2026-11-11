#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+77;
ll n,m,a[N],sum[N],ans = 0;


int main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> a[i];

    stable_sort(a + 1,a + 1 + n);

    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    for(int i = 0;i <= n;i++) sum[i] += m;


    if(m == 0)
    {
        ll f = 0;

        for(int i = 1;i <= n;i++)
        {
            ans = 0;
            if(a[i] == a[i + 1])
            {
                int k = i;
                while(a[k] == a[k+1] && k < n)
                {
                    ans++;
                    k++;
                }
                f = max(ans,f);
            }
        }

        cout << f+1;

        return 0;
    }

    int l = 0,r = n;
    ll len = (l + r) / 2;

    while(l < r && r - l > 1)
    {
        len = (l + r) / 2;

        for(int i = 1;i + len - 1 <= n;i++)
        {
            ll v = (sum[i + len - 1] - sum[i - 1] + m)/len;

            if(v >= a[i + len - 1])
            {

                l = len;
                ans = max(ans,len);
                break;
            }
        }

        if(l != len) r = len - 1;

    }


    cout << ans;


    return 0;

}
