#include<bits/stdc++.h>
using namespace std;
long long ans,C,n,m,d,q,xx[505][1005],k[505],v[500005],a[505][1005];
bool vis[500005];
void dfs2(int x,int y,long long sum){
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)return;
	for(int i=1;i<=n;i++){
		if(a[i][x]==0||vis[i])continue;
		sum+=a[i][x];
		vis[i]=1;
		for(int j=1;j<=k[i];j++){
			if(x==xx[i][j])continue;
//			cout<<i<<' '<<j<<'\n';
			sum+=a[i][xx[i][j]];
			dfs2(xx[i][j],y,sum);
			sum-=a[i][xx[i][j]];
		}
		vis[i]=0;
		sum-=a[i][x];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int y;
			cin>>xx[i][j]>>y;
			a[i][xx[i][j]]=y;
		}
	}
	while(q--){
		ans=INT_MAX;
		int l,r;
		cin>>l>>r;
		dfs2(l,r,0);
		cout<<ans+v[l]+v[r]<<'\n';
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
2 1
*/
