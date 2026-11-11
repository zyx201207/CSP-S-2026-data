#include<bits/stdc++.h>
using namespace std;
pair<int, char> a[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int n, m;
    long long len = 0;
    char c;
    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        cin >> m >> c;
        a[i] = {m, c};
        len += m;
    }
    int l = 1, r = n;
    long long pl = 1, pr = len;
    long long ans = 0;
    while(pl <= pr)
    {
        int le = min(a[l].first, a[r].first);
        if(a[l].second != a[r].second) ans += le;
        pl += le;
        pr -= le;
        a[l].first > le ? a[l].first -= le : l++;
        a[r].first > le ? a[r].first -= le : r--;
    }
    cout << ans;
    return 0;
}
