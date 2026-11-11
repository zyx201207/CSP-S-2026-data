#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<pair<int,int> > g[500005];
int a[500005],dis[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int k,ai,ti;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ai>>ti;
			g[ai].push_back({i,ti});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		if(g[i].size()==1)continue;
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int l=g[i][j].first,r=g[i][k].first,s=g[i][j].second+g[i][k].second;
				if(l>r)swap(l,r);
				dis[l][r]=min(dis[l][r],s);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=2026103115192026;
		for(auto l:g[x]){
			for(auto r:g[y]){
				int ds=l.second+r.second,dl=l.first,dr=r.first;
				if(dl>dr)swap(dl,dr);
				int ns=ds+dis[dl][dr];
				//cout<<ds<<" "<<dl<<" "<<dr<<" "<<dis[dl][dr]<<"\n";
				ans=min(ans,ns);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
}
/*
68 min
n sure 
*/ 
