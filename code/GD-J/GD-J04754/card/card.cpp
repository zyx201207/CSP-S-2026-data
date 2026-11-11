#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,ans = 0;
int a[N],d[N];
int sum[N],vis[N] = {0};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		sum[i] = a[i];
		for(int j = i; j <= n; j++){
			for(int q = i; q <= j; q++){
				int f = 0;
				if(sum[q] == a[j]){
					sum[q] = 0;
					for(int k = i; k <= q; k++){
						vis[k] = 0;
					}
					for(int k = q; k < j; k++){
						sum[k] = sum[k - 1] + a[k];
						f = 1;
					}
					if(f == 1){
						break;
					}
				}
			}
			sum[j] = sum[j - 1] + a[j];
			vis[j] = 1;
		}
		for(int j = i; j <= n; j++){
			if(vis[j] != 0){
				d[a[j]]++;
			}
		}
	}
	for(int j = 1; j <= n; j++){
		if(d[a[j]] == 0){
			continue;
		}else{
			cout << d[a[j]] << " ";
			d[a[j]] = 0;
		}
	}
	return 0;
} 
