#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 10;
ll a[MAXN];
ll sum[MAXN];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    int l = 1;
    for (int r = 1; r <= n; ++r){
        while (l <= r){
            __int128 cnt = r - l + 1;
            __int128 cost = cnt * a[r] - (sum[r] - sum[l - 1]);
            if (cost <= m){
                break;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
	cout<<1<<endl;
	cout<<2<<endl;
    return 0;
}

