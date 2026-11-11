#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int c,n,m,d,q;
int w[500010];
int val[510][510],cnt[500010];
struct node{
	int p,t;
}co[500010][25];
void tomin(int&x,int y){
	x=min(x,y);
}
int f[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			co[a][++cnt[a]]={i,t};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				val[i][j]=inf;
			}else{
				val[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				tomin(val[co[i][j].p][co[i][k].p],co[i][j].t+co[i][k].t);
				val[co[i][k].p][co[i][j].p]=val[co[i][j].p][co[i][k].p];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j&&val[i][j]){
//				cerr<<"?????\n";
//			}
//			if(val[i][j]!=inf)cerr<<val[i][j]<<' ';
//		}
//		cerr<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,co[x][i].t+co[y][j].t+val[co[x][i].p][co[y][j].p]);
			}
		}
		cout<<(ans+w[x]+w[y])<<endl;
	}
	return 0;
}
