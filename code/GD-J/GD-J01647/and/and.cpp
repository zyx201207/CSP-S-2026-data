#include<bits/stdc++.h>
using namespace std;
bool vis[200005],f[200005][32];
int n,m,ans,maxc,a[200005],c[32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = 29;j >= 0;j--){
			if(a[i] >= (1 << j)){
				f[i][j] = true;
				a[i] -= (1 << j);
				c[j]++;
			}
		}
	}
	for(int i = 29;i >= 0;i--){
		if(c[i] >= m){
			maxc = i;
			break;
		}
	}
	while(maxc != -1){
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			if(!f[i][maxc]){
				vis[i] = true;
				for(int j = 0;j <= maxc;j++)
					c[j] -= f[i][j];
			}
		}
		ans += (1 << maxc);
		int tmp = maxc;
		maxc = -1;
		for(int i = tmp - 1;i >= 0;i--){
			if(c[i] >= m){
				maxc = i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
