#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long w[500005],k[505],ans,a,t;
long long sh[505][505];
vector<pair<long long,long long> >v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(sh,0x3f3f3f,sizeof(sh));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			for(auto it:v[a]){
				int V=it.first,T=it.second;
				sh[i][V]=min(sh[i][V],T+t);
				sh[V][i]=min(sh[V][i],T+t);
			}
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			for(int k=1;k<=n;k++){
				if(k==i||k==j)continue;
				sh[i][j]=min(sh[i][j],sh[i][k]+sh[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=INT_MAX;
		for(auto i:v[x]){
			for(auto j:v[y]){
				if(i.first==j.first)ans=min(ans,i.second+j.second);
				else ans=min(ans,i.second+j.second+sh[i.first][j.first]);	
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

