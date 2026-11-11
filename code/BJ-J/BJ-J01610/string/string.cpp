#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200005];
char c[200005];
int b[200005];
char d[200005];
vector<int> v;
int ans;
int l = 0;
int s[200005];
int t[200005];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> c[i],
        l += a[i];
    for(int i = 1; i <= n; i++)
        b[i] = a[n - i + 1],
        d[i] = c[n - i + 1];
    s[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        v.push_back(s[i]);
        s[i+1] = s[i] + a[i];
    }
    t[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        v.push_back(t[i]);
        t[i+1] = t[i] + b[i];
    }
    sort(v.begin(), v.end());
    int m = v.size();
    for(int i = 0; i < m - 1; i++)
    {
        int posa = upper_bound(s + 1,s + n + 1, v[i]) - s - 1;
        int posb = upper_bound(t + 1,t + n + 1, v[i]) - t - 1;
        if(c[posa] != d[posb]) ans += v[i + 1] - v[i];
        //cout << v[i] << '\n';
    }
    int posa = upper_bound(s + 1,s + n + 1, v[m-1]) - s - 1;
    int posb = upper_bound(t + 1,t + n + 1, v[m-1]) - t - 1;
    if(c[posa] != d[posb]) ans += l + 1 - v[m-1];
    cout << ans / 2;
    

    return 0;
}