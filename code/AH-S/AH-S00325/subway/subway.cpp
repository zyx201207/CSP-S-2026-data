#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}ji[500010][510];
int c,n,m,d,q;
int a[500010];
int t[500010];
int u,v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
		for(int j=1;j<=t[i];j++){
			
			cin>>u>>v;
			ji[j][i].x=u,ji[j][i].y=v;
		}
	}
	while(q--){
		cin>>u>>v;
		long long ans=0;
		ans+=a[u]+a[v];
		ans+=ji[u][1].y;
		ans+=ji[v][1].y;
		cout<<ans<<endl;
	}
	return 0;
}
