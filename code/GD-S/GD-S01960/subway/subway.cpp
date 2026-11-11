#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,x,y,m,a[550005],cnt,ans,l,sum,c,d,q,w,p,mi;
vector <pair<long long,long long> > vn[550005];
long long ve[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=m;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>w;
			vn[x].push_back({w,i});
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			ve[i][j]=1e18;
			if(i==j){
				ve[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<vn[i].size();j++){
			for(k=0;k<vn[i].size();k++){
				if(ve[vn[i][j].second][vn[i][k].second]>vn[i][j].first+vn[i][k].first) ve[vn[i][j].second][vn[i][k].second] =vn[i][j].first+vn[i][k].first;
			}
		}
	}
	for(k=1;k<=m;k++){
		for(i=1;i<=m;i++){
			for(j=1;j<=m;j++){
				ve[i][j]=min(ve[i][j],ve[i][k]+ve[k][j]);	
			}
		}
	}
//	for(i=1;i<=m;i++){
//		for(j=1;j<=m;j++){
//			cout<<ve[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(i=1;i<=q;i++){
		cin>>x>>y;
		mi=1e18;
		for(j=0;j<vn[x].size();j++){
			for(k=0;k<vn[y].size();k++){
				mi=min(mi,ve[vn[x][j].second][vn[y][k].second]+vn[x][j].first+vn[y][k].first);
			}
		}
		//cout<<mi<<' ';
		mi+=a[x]+a[y];
		cout<<mi<<endl;
	}
	return 0;
} 
