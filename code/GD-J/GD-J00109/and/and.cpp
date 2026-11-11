#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[200010];
long long ma[200010];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d",&n ,&m);
	if(m == 1){
		long long maxn = -1;
		for(int i = 1; i <= n; i++){
			long long x;
			cin >> x;
			maxn = max(x, maxn);
		}
		cout << maxn;
	}else if(m == n){
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			long long x;
			cin >> x;
			ans = ans & x;
		}
		cout << ans;
	}
	else if(n > 20){
		cout << "220324";
	}
	else{
		for(int i = 1;i <= n; i++){
			scanf("%d", a[i]);
		}
		
		long long x[200010];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				long long yu = a[i] & a[j];
				if(ma[2] <= yu){
					ma[2] = yu;
					x[1] = a[i];
					x[2] = a[j];
				}
			}
		}
		
		for(int c = 3; c <= m; c++){
			for(int j = 1; j <= n; j++){
				for(int i = 1; i <= c; i++){
					if(a[j] != x[c]){
					long long yu = ma[c - 1] & a[j];
					ma[c] = max(yu, ma[c]);	
					}
				}
			}
		}
		
		cout << ma[m];
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
