#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500100];
vector<pair<int,int> > ps[500100];
long long dis[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;cin>>k;
		while(k--){
			cin>>a>>t;
			ps[a].push_back({t,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e17;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int l=ps[i].size();
		for(int j=0;j<l;j++){
			for(int k=0;k<j;k++){
				int x=ps[i][j].second,y=ps[i][k].second;
				dis[x][y]=dis[y][x]=min(dis[x][y],(long long)ps[i][j].first+ps[i][k].first);
			}
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int s,t;
		cin>>s>>t;
		if(s==t){
			cout<<"0\n";
			continue;
		}
		long long ans=1e17;
		for(int i=ps[s].size()-1;i>=0;i--)
		for(int j=ps[t].size()-1;j>=0;j--)
			ans=min(ans,dis[ps[s][i].second][ps[t][j].second]+ps[s][i].first+ps[t][j].first);
		ans+=w[s]+w[t];
		cout<<ans<<"\n";
	}
}