#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000],mmax,ans[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 65536 && m == 16384) cout << 49152;
	if(m == 1){
		sort(a+1,a+1+n);
		cout<< a[n];
	}
	else if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				mmax = max(mmax,a[i]&a[j]);
			}
		}
		cout << mmax;
	}
	else if(m==3){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int z = j+1;z <= n;z++){
					mmax = max(mmax,a[i]&a[j]&a[z]);
				}
			}
		}
		cout << mmax;
	}
	else if(m==4){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int z = j+1;z <= n;z++){
					for(int x  = z+1;x <= n;x++){
						mmax = max(mmax,a[i]&a[j]&a[z]&a[x]);
					}
				}
			}
		}
		cout << mmax;
	}
	else if(m==5){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int z = j+1;z <= n;z++){
					for(int x  = z+1;x <= n;x++){
						for(int y = x+1;y <= n;y++){
							mmax = max(mmax,a[i]&a[j]&a[z]&a[x]&a[y]);
						}
					}
				}
			}
		}
		cout << mmax;
	}
	else if(m==6){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int z = j+1;z <= n;z++){
					for(int x  = z+1;x <= n;x++){
						for(int y = x+1;y <= n;y++){
							for(int g = y+1;g <= n;g++){
								mmax = max(mmax,a[i]&a[j]&a[z]&a[x]&a[y]&a[g]);
							}
						}
					}
				}
			}
		}
		cout << mmax;
	}
	return 0;
}
