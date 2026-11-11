#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define cfalse cin.tie(0)->sync_with_stdio(0)
const int maxn = 6e5 + 5;
int n, m, ans = 1;
vector<int>t;
vector<int>pre;
bool check(int pos, int sum, int p){
    int a, b, len = p - pos;
    if(pos == 0) b = 0;
    else b = pre[pos - 1];
    a = pre[p - 1];
    if(sum * len - (a - b) > m) return 0;
    else return 1;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cfalse;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        t.push_back(x);
    }
    sort(t.begin(), t.end());
    pre.push_back(t[0]);
    for(int i = 1; i < n; i++){
        pre.push_back(t[i] + pre[i - 1]);
    }
    for(int i = 1; i < n; i++){
        int x = t[i];
        int l = -1, r = i;
        while(l + 1 < r){
            int mid = (l + r) >> 1;
            if(check(mid, x, i)) r = mid;
            else l = mid;
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans;
    return 0;
}
