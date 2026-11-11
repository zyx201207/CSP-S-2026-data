#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long a[1005][1005],w[100005],h[1005][1005],t[1005][1005],u[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i= 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
			h[i][a[i][j]]++;
			u[a[i][j]]++;
		}
	}
	for(p;p>0;p--){
		long long s = 0;
		long long r,e;
		cin >> r >> e;
		long long k;
		s = w[r]+w[e];
		for(int i = 1;i <= n;i++){
			if(h[i][r]){
				if(h[i][e]){
				cout << s+t[i][r]+t[i][e];	
				}else{
					for(int j = 1;j <= n;j++){
						if(u[j])
						cout << s+t[i][r]+t[i][e]+t[1][u[j]]+t[2][u[j]];
					}
				
				}	
			}
		}
	}
	return 0;
}
