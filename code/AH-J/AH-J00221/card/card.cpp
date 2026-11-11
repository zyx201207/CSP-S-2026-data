#include<bits/stdc++.h>

using namespace std;

int n, m;
long long ans[300005];
int a[500005];
//rp++ 歪比八部

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s1 = "";
    for (int i = 1; i <= m + 1; i++)
        s1 += "0";
    for (int i = 1; i <= n; i++) {
        string s = s1;
        for (int j = i; j <= n; j++) {
            if (s[a[j]] == '1')
                s = s1;
            s[a[j]] = '1';
        }
        for (int j = 1; j <= m; j++)
            if (s[j] == '1')
                ans[j]++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
