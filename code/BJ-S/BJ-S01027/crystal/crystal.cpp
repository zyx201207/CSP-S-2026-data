#include <bits/stdc++.h>
#define ll long long
using namespace std;
// s is the max of that time
//tmp_num is the sum of m
//tmp_ans is the count of ans
const int maxn = 500005;
int n, s;
ll a[maxn], m, ans;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    if(m>1000000000) {
        ll i=1;
        while((1+i)*i/2-i<m)
            i++;
        cout << i;
        return 0;
    }
    sort(a+1, a+n+1);
    if(m==0) {
        cout << 0;
        return 0;
    }
    for(ll i=a[1];i<=a[n];i++) {
        while(a[s]<=i&&s<n)
            s++;
        ll tmp_num = 0, tmp_ans = 0;
        for(ll j=s-1;j>=1;j--) {
            tmp_num+=i-a[j];
            if(tmp_num>m)
                break;
            tmp_ans++;
        }
        ans = max(ans, tmp_ans);
    }
    cout << ans;
    return 0;
}
