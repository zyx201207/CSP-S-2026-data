#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10; 
int C,n,m,d,q;
ll dis[510][510],w[N];
vector<pair<int,ll> >bel[N];
void f(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dis[i][j]=1e17;
		}dis[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		if(bel[i].size()>1){
			for (int j=0;j<bel[i].size();j++){
				for (int k=0;k<bel[i].size();k++){
					if(j==k)continue;
					int l=bel[i][j].first,r=bel[i][k].first;
					int t1=bel[i][j].second,t2=bel[i][k].second;
					ll W=t1+t2;
					dis[l][r]=dis[r][l]=W;
				}
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>C>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int id;ll T;
			cin>>id>>T;
			bel[id].push_back({i,T});
		}
	}
	f();
	for (int i=1;i<=q;i++){
		ll num=0,res=0,ans=1e18;
		int x,y;
		cin>>x>>y;
		num=w[x]+w[y];
		for (int j=0;j<bel[x].size();j++){
			int l=bel[x][j].first;
			int t1=bel[x][j].second;
			for (int k=0;k<bel[y].size();k++){
				int r=bel[y][k].first;
				int t2=bel[y][k].second;
				res=num+t1+t2+dis[l][r];
				ans=min(res,ans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
