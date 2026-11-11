#include <bits/stdc++.h>
using namespace std;
int a[2000005];
bool vis[2005][2005];
int cnt[2000005];
void dfs(int s,int x,int l){
	if(s >= x){
		cnt[l]++;
		return ;
	}
	for(int i=s+1;i<=x;i++){
		if(!vis[s][i]) continue;
		dfs(i,x,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			vis[i][i] = 1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i] <= d) vis[i][j] = 1;
			}
		}
		long long sum = 0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,j,1);
				for(int l=2;l<=2000001;l++){
					if(cnt[l] != 0){
						if(cnt[l] == 2){
							sum++;
						}else{
							break;
						}
					}
				}
				memset(cnt,0,sizeof(cnt));
			}
		}
		memset(vis,0,sizeof(vis));
		cout << sum << endl;
	}
	return 0;
}
