#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,a[N];
long long ans = 0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1,greater<>());
	if(n <= 20){
        for(int i = 1;i < (1 << n);i++){
            long long x = 0,cnt = 0;
            for(int j = 0;j < n;j++){
                if(i >> j & 1){
                    if(x == 0) x = a[j + 1];
                    else x = x & a[j + 1];
                    ++cnt;
                }
            }
            if(cnt == m) ans = max(ans,x);
        }
        cout << ans;
	}
	else if(m == 1) cout << a[1];
	else if(m == 2){
		for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                long long x = a[i] & a[j];
                ans = max(ans,x);
            }
		}
		cout << ans;
	}else if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans = ans & a[i];
		}
		cout << ans;
	}else if(m == n - 1){
	    ans = a[1];
	    for(int i = 2;i < n;i++){
            ans = ans & a[i];
	    }
	    cout << ans;
    }else{
        ans = a[1];
        for(int i = 2;i <= m;i++){
            ans = ans & a[i];
        }
        cout << ans;
    }
	return 0;
}
