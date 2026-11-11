#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200007];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int ans=0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m==n){
		ans = a[1];
		for(int i = 2; i <= n; i++) ans &= a[i];
	}else if(m==1){
		sort(a+1,a+n+1);
		ans = a[n];
	}else if(m==2){
		for(int i = 1; i < n; i++){
			for(int j = i+1; j <= n; j++){
				if(a[i] & a[j] > ans) ans=a[i] & a[j];
			}
		}
	}else if(m==3){
		for(int i = 1; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				for(int k = j+1; k <= n; k++){
					int cnt = a[i] & a[j] & a[k];
					if(cnt > ans) {
						ans = cnt;
					}
				}
			}
		}
	}else if(m==4){
		for(int i = 1; i < n-2; i++){
			for(int j = i+1; j < n-1; j++){
				for(int k = j+1; k < n; k++){
					for(int t = k+1; t <= n; t++){
						int cnt = a[i] & a[j] & a[k] & a[t];
						if(cnt > ans) ans=cnt;
					}
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
