#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N];
multiset<int> s;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int l = 1, su = 0, ans = 0;
    // s.insert();
    for(int i = 1; i <= n; i++){
        su += a[i]; s.insert(a[i]);
        while((*(--s.end()))*(i-l+1)-su > m){
            s.erase(s.find(a[l]));
            su -= a[l];
            l++;
        }
        ans = max(ans, i-l+1);
    }
    cout << ans;
    return 0;
}