#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sum /= n;
    ll val;
    ll keep = LLONG_MAX;
    for(ll i = 0; i < n; i++)
    {
        ll tmp = abs(sum - arr[i]);
        if(tmp < keep)
        {
            keep = tmp;
            val = arr[i];
        }
    }

    vector<ll> cha(n);
    for(ll i = 0; i < n; i++)
    {
        cha[i] = abs(val - arr[i]);
    }

    sort(cha.begin(), cha.end());

    ll idx = 0;
    ll res = 0;
    while(m >= cha[idx])
    {
        res++;
        m -= cha[idx];
        idx++;
    }

    cout << res << endl;
    return 0;
}
