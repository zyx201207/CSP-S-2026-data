#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[510];
int a[510][20020];
int t[510][20020];
int x;
int y;
int k[500500];
int ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i]*2;j++){
			if(j % 2 == 1){
				cin >> a[i][j];
			}else cin >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		int a1,b1;
		int a2,b2;
		for(int j = 1;j <= n;j++){
			for(int l = 1;l <= k[j];l++){
				if(a[j][l*2-1] == x){
					a1 = j;
					a2 = a[j][l*2-1];
				} 
				if(a[j][l*2-1] == y){
					b1 = j;
					b2 = a[j][l*2-1];
				} 
			}
		}
		if(a1 == b1){
			ans+=(w[x]+w[y]);
			ans+=(a2+b2);
			cout << ans;
		}
	}
	 
	return 0;
} 
