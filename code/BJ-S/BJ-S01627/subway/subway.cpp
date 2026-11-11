#include<bits/stdc++.h>
using namespace std;
int a[500001][500001],t[500001][500001];
int c,n,m,d,q,xr,yr,ans = 9999999;
int w[500001],k[500001];
int dfs(int place,int time){
	if(place == yr){
		return time;
	}
	for(int i = 1;i <= d; i ++){
		for(int j = 1;j <= k[i];j ++){
			if(a[i][j] == place && place < yr){
				for(int z = j+1;z <= k[i];z ++){
					int time2 = time + 2*t[i][z];
					ans = min(ans,dfs(a[i][z],time2 ));
				}
			}
			if(a[i][j] == place && place > yr){
				for(int z = k[i];z >= j+1;z --){
					int time2 = time + 2*t[i][z];
					ans = min(ans,dfs(a[i][z],time2 ));
				}
			}
		}
	}
	return 99999;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin>> w[i] ;
	}
	for(int i = 1;i <= n;i ++){
		cin>> k[i] ;
		for(int j = 1;j <= k[i];j ++){
			cin>> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i ++){
		cin>> xr >> yr;
		dfs(xr,w[xr]);
		int ans2 = ans + w[yr];
		cout<<  ans2 << endl;
	}
	return 0;
}

