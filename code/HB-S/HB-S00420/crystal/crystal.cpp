#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], k[500005], l, r, ans;
bool solve(int x){
    for(int i = x; i <= n; i++){
        if(k[i] - k[i - x] >= x * a[i] - m)return 1;
    }
    return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    r = n;
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
		k[i] = k[i - 1] + a[i];
	}
    while(l < r){
        int mid = (r - l) / 2 + l;
        if((r - l) % 2 == 1) mid++;
        if(solve(mid)){
            ans = mid;
            l = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
