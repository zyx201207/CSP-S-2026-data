#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long opt,test,n,d,a[N],g[305][305],f[305][305];
long long t[N],cnt[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>opt>>test;
	if(opt > 10){
		while(test--){ 
			ans = 0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++){
				t[i] = upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				if(i >= 3){
					if(t[i-1] != t[i-2] && t[i-1] > i){
						ans += cnt[i] * (t[i-1]-i);
					}
				}
				cnt[t[i]] += cnt[i]+1;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(test--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++){
			g[i][i] = 0;
			f[i][i] = 1;
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j]) <= d){
					g[i][j] = 1;
					f[i][j] = 1;
				}else{
					g[i][j] = n*10;
					f[i][j] = 0;
				} 
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(g[i][k] + g[k][j] < g[i][j]){
						g[i][j] = g[i][k] + g[k][j];
						f[i][j] = f[i][k] * f[k][j];
					}else if(g[i][k] + g[k][j] == g[i][j]){
						f[i][j] += f[i][k] * f[k][j];
					}
				}
			}
		}
		ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j] == 2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
50MB
0 2
4 2
1 2 3 4 
5 2 
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
