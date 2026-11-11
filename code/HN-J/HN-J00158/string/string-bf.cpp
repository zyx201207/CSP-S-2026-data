#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 25;

int n;
pair<int, char>d[MAXN];
string p;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> d[i].first >> d[i].second;
        p += string(d[i].first, d[i].second);
    }
    int ans = 0;
    for(int i = 0; i < p.size() / 2; i++) {
    	if(p[i] != p[p.size() - 1 - i])ans++;
	}
	cout << ans;
    return 0;
}
