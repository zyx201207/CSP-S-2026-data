#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll w[1000006];
vector<vector<ll>> g(1000006);
vector<vector<ll>> r(1000006);
struct e{
	ll to,val;
};
vector<vector<ll>> v(1000006);
ll ki[1000006];
ll di[1010][1010];
ll c,n,m,d,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		ll last=0,a=0,val=0;
		for(int j=1;j<=ki[i];j++){
			cin>>a>>val;
			g[a].push_back(i);
			r[i].push_back(a);
			v[a].push_back(val);
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<g[i].size()<<"**\n";
//		for(int j:g[i])cout<<j<<" ";
//		cout<<"\n";
//	}
//	cout<<"\n\n";
//	for(int i=1;i<=m;i++){
//		cout<<v[i].size()<<"**\n";
//		for(int j:v[i])cout<<j<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			di[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		di[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(j>=k)continue;
				ll x=g[i][j],y=g[i][k];
//				cout<<x<<" "<<y<<"\n";
//				cout<<v[i][j]<<" "<<v[i][k]<<"\n";
				di[x][y]=min(di[x][y],v[i][j]+v[i][k]);
				di[y][x]=di[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<di[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	ll x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ll daan=1e18;
		for(int j=0;j<g[x].size();j++){
			for(int k=0;k<g[y].size();k++){
				ll fr=g[x][j],to=g[y][k];
//				cout<<fr<<" "<<to<<"\n";
//				cout<<v[x][j]<<" "<<v[y][k]<<"\n";
				daan=min(daan,di[fr][to]+v[x][j]+v[y][k]);
			}
		}
//		cout<<"\n";
		cout<<daan+w[x]+w[y]<<"\n";
	}
//	cout<<q<<"\n";
	return 0;
}
