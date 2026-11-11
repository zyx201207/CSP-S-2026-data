#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 50;
int n,m,a[N],ans = 1,f = 0,f1 = 0,n1 = 0;
int32_t main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; ++ i){
		cin >> a[i];
		if(a[i] != i) f = 1;
	}
	n1 = a[2] - a[1];
	for(int i = 3;i <= n; ++ i){
		if(a[i] - a[i - 1] != n1) f1 = 1;
	} 
	if(m == 0){
		int mx = 1;
		map<int,int> q;
		for(int i = 1;i <= n; ++ i){
			q[a[i]] ++;
			mx = max(mx,q[a[i]]);
		}
		cout << mx;
		return 0;
	}
	if(!f){
		for(int i = 1;i <= n; ++ i){
			if(m < (i - 1) * i / 2){
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if(!f1){
		for(int i = 1;i <= n; ++ i){
			if(m < (i - 1) * i / 2 * n1){
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n; ++ i){
		int x = m,sum = 1;
		for(int j = 1;j < i; ++ j){
			if(x >= a[i] - a[j]){
				x-= a[i] - a[j];
				sum ++;	
			} 
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
} 
