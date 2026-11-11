#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int n, ans;
LL m, a[N], pre[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	bool f = 0, fl = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		
		if(a[i] != i) f = 1;
		if(a[i] - a[i - 1] != a[1]) fl = 1;
	}
	
	if(!fl){
		for(int i = 2; i <= n; ++i){
			pre[i] = a[1] * (i - 1) + pre[i - 1];
			
			if(pre[i] >= m){
				cout << i - 1 << "\n";
				return 0;
			}
		}
	}
	if(!f){
		for(int i = 2; i <= n; ++i){
			pre[i] = i - 1 + pre[i - 1];
			
			if(pre[i] >= m){
				cout << i - 1 << "\n";
				return 0;
			}
		}
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int j = 2; j <= n; ++j){
		pre[j - 1] = 0;
		
		for(int i = j; i <= n; ++i){
			pre[i] = (a[i] - a[i - 1]) * (i - 1) + pre[i - 1];
			
			if(pre[i - 1] <= m && pre[i] > m){
				ans = max(ans, i - j + 1);
				break;
			}
		}	
	}
	
	cout << ans << "\n";
	return 0;
}
