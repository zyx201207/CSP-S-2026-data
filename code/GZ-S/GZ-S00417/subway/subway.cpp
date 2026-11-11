//GZ-S00417 左成毅 黔南布依族苗族自治州都匀第一中学 

#include<bits/stdc++.h>
using namespace std;

long long w[500005],t[505][21],dp[500][500];
long long ans = 0;

int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i = 0;i < m;i++){
		cin>>w[i];
	}
	for(int i = 0;i < n;i++){
		int p;
		cin>>p;
		for(int j = 0;j < p;j++){
			int x,y;
			cin>>x>>y;
			t[i][x] = y;
		}
	}
	for(int f = 0;f < q;f++){
		int x,y;
		cin>>x>>y;
		ans += (w[x] + w[y]);
		int j = x;
		while(j != y){
			for(int i = 0;i < n;i++){
				if(t[i][j] == 0)continue;
				else if(t[i][j] != 0){
					ans += t[i][j];
					for(int k = 0;k < q;k++){
						if(t[i][k] != 0 && k != j){
							ans += t[i][k];
							j = k;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
		
		
		
		
		
		
		
		
