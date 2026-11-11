#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f[35];
bool a[200005][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1,x;i <= n;i++){
		cin >> x;
		int j = 0;
		while(x > 0){
			if(x & 1){
				a[i][j] = 1;
				f[j]++;
			}
			x >>= 1;
			j++;
		}
	}
	for(int i = 30;i >= 0;i--){
		if(f[i] >= m){
			memset(f,0,sizeof(f));
			ans += pow(2,i);
			for(int j = 1;j <= n;j++){
				if(a[j][i] && !a[j][31]){
					for(int k = i - 1;k >= 0;k--){
						f[k] += a[j][k];
					}
				}else{
					a[j][31] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
