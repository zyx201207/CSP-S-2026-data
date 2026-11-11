#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i8 = __int128;
void sv();
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
}
int main()
{
    fre();
    int T = 1; //cin >> T;
    while (T--) v();
    return 0;
}

int a[11451419];
void sv()
{
    int n, m;
    cin >> n >> m;
    map<int,int>mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int maxn = -1;
    for (auto x : mp)
        maxn = max(x, maxn);
    
}