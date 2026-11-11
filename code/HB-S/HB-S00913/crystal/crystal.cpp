#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull n,m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<ll> tmp(n), df(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> tmp[i];
    }
    sort(tmp.begin(), tmp.end());
    
    for (ll i = 0; i+1 <n; i++)
    {
        df[i] = tmp[i+1] - tmp[i];
    }

    ull ans = 0;
    ull otto;
    for (ull i = 1; i <= n; i++)
    {
        otto = df[i-1] * i;
        if (m >= otto)
        {
            m-=otto;
        }
        else
        {
            break;
        }
        
        ans += 1;
    }
    
    cout << ans+1;
    return 0;
}