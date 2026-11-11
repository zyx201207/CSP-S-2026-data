#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],a[1005][1005],t[1005][1005],x,y,fa[1005][1005];
bool f[1005][1005];
int minn=10000005;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			f[i][a[i][j]]=1;
			fa[i][a[i][j]]=j;
		}
	}
	for(int i = 1;i <= q;i++){
		minn=10000005;
		cin >> x >> y;
		for(int j = 1;j <= n;j++){
			if(f[j][x]==1){
				for(int p = 1;p <= n;p++){
					if(f[p][y]==1){
						if(j==p){
							minn=min(minn,w[x]+w[y]+t[j][x]+t[j][y]);
						}
						else{
							for(int o = 1;o <= m;o++){
							
									if(f[j][o]==1&&f[p][o]==1){
										
										minn=min(minn,w[x]+t[j][fa[j][x]]+t[j][fa[j][o]]+t[p][fa[p][o]]+t[p][fa[p][y]]+w[y]);
									}
							
							}
						}
					}
				}
			}
		}
		cout << minn << "\n";
	}
	return 0;
}

