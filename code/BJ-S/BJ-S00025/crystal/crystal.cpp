#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a[int(5 * 1e5 + 1)], ans[int(5 * 1e5 + 1)], max_ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i = 1;i <= n;i++) cin>>a[i];

    sort(a + 1, a + n + 1);
    a[0] = a[1];

    bool flag = m > 1e8;

    for(int r = 1;r <= n - max_ans;r++)
    {
        for(ll i = 1;i <= n;i++)
        {
            if((a[i] - a[i - 1]) * (i - r)  > m) break;
            m -= (a[i] - a[i - 1]) * (i - r);
            ans[r] ++;

        }
         max_ans = max(max_ans,ans[r]);


        if(flag) break;


    }

    cout<<max_ans;

    return 0;
}
