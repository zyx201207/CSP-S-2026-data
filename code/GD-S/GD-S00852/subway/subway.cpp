#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],road[4002][4002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(road,0x3f,sizeof(road));
	int o;
	for(int i=1;i<=n;i++){
		long long a[1005][5];
		cin>>o;
		for(int j=1;j<=o;j++){
			cin>>a[j][1]>>a[j][2];
		}
		for(int k=1;k<o;k++){
			for(int j=k+1;j<=o;j++){
				road[a[k][1]][a[j][1]]=min(road[a[k][1]][a[j][1]],a[k][2]+a[j][2]);
				road[a[j][1]][a[k][1]]=min(road[a[j][1]][a[k][1]],a[k][2]+a[j][2]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		road[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
			}
		}
	}
	while(q--){
		int r,l;
		cin>>r>>l;
		cout<<road[r][l]+w[r]+w[l]<<endl;
	}
	return 0;
}
