#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500050];
long long sum[500050];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    long long ans = 1;
    for(int i = 2; i <= n; i++){
        long long l = 1, r = i - 1, cnt = 0;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m){
                r = mid - 1;
                cnt = mid;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans, i - cnt + 1);
    }
    cout << ans;
}
