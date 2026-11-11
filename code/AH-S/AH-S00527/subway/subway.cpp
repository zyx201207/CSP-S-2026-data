#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x[500005],y,h[500005];
int w[500005],ans[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			ans[i][j]=2100000000;
		}
		ans[i][i]=0;
	}
	for(int i=1;i<=n;i++){//500
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){//500005
			cin>>x[j]>>y;
			h[x[j]]=y;
			for(int o=1;o<=j;o++){//500005
				ans[x[o]][x[j]]=h[x[o]]+h[x[j]];
				ans[x[j]][x[o]]=h[x[o]]+h[x[j]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			int vmin=1;
			for(int g=1;g<=m;g++){
				if(vis[i][g]==0&&ans[i][g]<ans[i][vmin]) vmin=g;
			}
			cout<<vmin<<" ";
			vis[i][vmin]=1;
			for(int g=1;g<=m;g++){
				ans[i][g]=min(ans[i][g],ans[i][vmin]+ans[vmin][g]);
			}
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
