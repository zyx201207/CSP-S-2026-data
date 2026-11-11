#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 7;

ll n, a[N], ans, len[N];
char c[N];

int main()
{
    // string
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n; ll sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i]; len[i] = a[i];
        string s; cin >> s;
        c[i] = s[0];
        sum += a[i];
    }
    ll l = 1, r = n;
    while(l < r) {
        if(c[l] ^ c[r]) {
            ans += min(len[l], len[r]);
            if(len[l] < len[r]) {
                len[r] -= len[l];
                ++l;
            } else if(len[l] > len[r]) {
                len[l] -= len[r];
                --r;
            } else {
                ++l, --r;
            }
        }
        else {
            if(len[l] < len[r]) {
                len[r] -= len[l];
                ++l;
            } else if(len[l] > len[r]) {
                len[l] -= len[r];
                --r;
            } else {
                ++l, --r;
            }
        }
    }
    cout << ans;
    return 0;
}