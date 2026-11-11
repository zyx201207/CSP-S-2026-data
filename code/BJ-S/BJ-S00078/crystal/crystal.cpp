#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn];

void solve(){
    long long n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }


    sort(a + 1,a + n + 1);
    long long u = a[2] - a[1];
    bool flag = true;
    for(int i = 2;i <= n;i++)
    {
        if(a[i] - a[i - 1] != u)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        long long sum = 0;
        for(int i = 1;i <= n - 1;i++)
        {
            if(m >= sum + i * u)
            {
                sum += i * u;
            }
            else
            {
                cout << i;
                return  ;
            }
        }
    }


    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            long long o = m;
            int cnt = 0;
            for(int k = j;k <= i;k++)
            {
                if(m - (a[i] - a[k]) >= 0)
                {
                    m -= a[i] - a[k];
                    cnt++;
                }
                else break;
            }
            m = o;
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
