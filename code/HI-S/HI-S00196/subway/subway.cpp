#include<bits/stdc++.h>
using namespace std;
int tim,n,m,lim,t,num[500005],l,r;
vector<pair<int,int> >a[500005];
long long mp[505][505],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tim>>n>>m>>lim>>t;
	memset(mp,63,sizeof(mp));
	for(int i=1;i<=n;i++)mp[i][i]=0;
	for(int i=1;i<=m;i++)scanf("%d",&num[i]);
	for(int i=1,k,x,y;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&x,&y);
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:a[i]){
			for(auto y:a[i]){
				if(x.first==y.first)continue;
				mp[x.first][y.first]=x.second+y.second;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(t--){
		scanf("%d%d",&l,&r);
		ans=1e18;
		for(auto x:a[l]){
			for(auto y:a[r]){
				ans=min(ans,mp[x.first][y.first]+x.second+y.second);
			}
		}
		printf("%lld\n",ans+num[l]+num[r]);
	}
	return 0;
}
/*

*/
