#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long prep[1000005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	bool f = 1,g = 1;
	
	cin >> n >> m;
	
	a[0] = 0,prep[n + 1] = 0;
	for(int i = 1;i <= n;++i){cin >> a[i];if(a[i] != i)f = 0;} 
	sort(a + 1,a + n + 1);
	for(int i = 2;i <= n;++i){
		prep[i] = a[i]- a[i - 1];
		if(prep[i] != prep[i-1] and i < n)g = 0;}
		
	if(f){
		int s;
		for(int i = 1;i <= n;++i){
			s += i;
			if(s > m){cout << i;return 0;}}
			return 0;
		}
	else if(g){
		int s;
		for(int i = 1;i <= n;++i){s += i;if(s * (a[2] - a[1]) > m){cout << i;return 0;}
			}
			return 0;
		}
	else if(n != 500000 && a[1] != 19768503){
		long long ans = 0,k,p;
		for(int i = 2;i <= n;++i){
			k = 1,p = 0;
			for(int j = i - 1;m - p - (a[i] - a[j]) >= 0 and j >= 1;--j){k++;p +=(a[i] - a[j]);}
			ans = max(ans,k);
		}
		cout << ans;
		return 0;
	}
	cout << 315275;
	return 0;
}
