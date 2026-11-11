# include<bits/stdc++.h>
# define int long long
using namespace std;
int c,n,m,d,q,flo[505][505],K,ip1,ip2,ans,w[1000005];
vector<pair<int,int>>A[1000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(flo,127/3,sizeof(flo));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		flo[i][i]=0;
		cin>>K;
		while(K--)cin>>ip1>>ip2,A[ip1].push_back({ip2,i});
	}
	for(int i=1;i<=m;i++)for(auto j:A[i])for(auto k:A[i])
	flo[j.second][k.second]=min(flo[j.second][k.second],j.first+k.first);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)
	flo[j][k]=min(flo[j][k],flo[j][i]+flo[i][k]);
	while(q--){
		cin>>ip1>>ip2,ans=1ll<<60;
		for(auto i:A[ip1])for(auto j:A[ip2])ans=min(ans,flo[i.second][j.second]+i.first+j.first);
		cout<<ans+w[ip1]+w[ip2]<<"\n";
	}
}
