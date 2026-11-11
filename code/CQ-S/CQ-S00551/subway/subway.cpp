#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<pair<int,int> > v[500010];
int tid,n,m,tmp,q,len,t1,t2,v1,v2,be,en,ans,w[500010],dist[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tid>>n>>m>>tmp>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>t1>>t2;
			v[t1].push_back({i,t2});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dist[i][j]=0;
			else dist[i][j]=3e18;
	for(int i=1;i<=m;i++){
		for(t1=0;t1<v[i].size();t1++){
			for(t2=t1;t2<v[i].size();t2++){
				v1=v[i][t1].first,v2=v[i][t2].first;
				dist[v1][v2]=dist[v2][v1]=min(dist[v1][v2],v[i][t1].second+v[i][t2].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for(int i=1;i<=q;i++){
		cin>>be>>en;ans=3e18;
		for(t1=0;t1<v[be].size();t1++){
			for(t2=0;t2<v[en].size();t2++){
				v1=v[be][t1].first,v2=v[en][t2].first;
				ans=min(ans,dist[v1][v2]+v[be][t1].second+v[en][t2].second);
			}
		} 
		cout<<ans+w[be]+w[en]<<"\n";
	}
	return 0;
} 
