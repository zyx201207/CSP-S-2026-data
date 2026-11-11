#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> c(n);
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 0, r = n - 1;
    while(r > l && r >= 0 && l < n)
    {
        int m = min(a[l], a[r]);
        if(c[l] != c[r]) ans += m;
        a[l] -= m;
        a[r] -= m;
        if(a[l] == 0) l++;
        if(a[r] == 0) r--;
    }
    cout << ans << endl;
    return 0;
}
