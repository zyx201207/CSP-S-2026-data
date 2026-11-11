#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,cnt;
int dp[35],lg[N],ma = -1;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i<=n;i++){
			ma = max(ma,a[i]);
		}
	}else if(m == 2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					ma = max(ma,a[i]&a[j]);
				}
			}
		}
	}else if(m == 3){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					if(i!=j&&j!=k)ma = max(ma,a[i]&a[j]&a[k]);
				}
			}
		}
	}else if(m == 4){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					for(int l = 1;l<=n;l++){
						if(i!=j&&j!=k&&k!=l)ma = max(ma,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
	}else{
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k>=n;k++){
					for(int l = 1;l<=n;l++){
						for(int p = 1;p<=n;p++){
							if(i!=j&&j!=k&&k!=l&&l!=p)ma = max(ma,a[i]&a[j]&a[k]&a[l]*a[p]);
						}
					}
				}
			}
		}
	}
	cout << ma;
	return 0;
} 
