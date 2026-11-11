#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<int>w(m+1);
	for(int i=1;i<=m;i++) cin >> w[i];
	vector<vector<int>>a(1005,vector<int>(1005)),t(1005,vector<int>(1005));
	vector<int>k(n+1);
	vector<vector<int>>dis(m+1,vector<int>(m+1,1000000005));
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int x=1;x<=k[i];x++){
				dis[a[i][j]][a[i][x]]=min(dis[a[i][j]][a[i][x]],t[i][j]+t[i][x]);
			}
		}
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=k&&k!=j&&i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << dis[x][y]+w[x]+w[y] << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

