#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n,m;
int a[maxn],b[maxn],ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int u = 1;u <= n;u++) b[u] = a[u];
		for(int j = i;j <= n;j++){
			for(int k = j+1;k <=j+m&&k <= n;k++){
				if(a[j] == a[k]){
					for(int d = j;d < k;d++) b[d] = 0;
					j = k; 
					break;
				}
			}
		}
		for(int l = i;l <= n;l++){
			if(b[l] != 0){
				ans[b[l]]+=1;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
