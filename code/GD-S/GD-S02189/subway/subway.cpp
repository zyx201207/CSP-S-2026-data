#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans,w[500005],a[500005];
vector<pair<int,int> > g[505];
int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin >>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++) cin >>w[i];
	for(int i=1,len;i<=n;i++){
		cin >>len;
		for(int j=1,x,y;j<=len;j++) cin >>x>>y,g[i].push_back({x,y}),a[x]=min(a[x],y);
	}
	for(int i=1,x,y;i<=q;i++){
		cin >>x>>y,ans=0;
		cout<<w[x]+a[x]+a[y]+w[y]<<"\n";
	}
	return 0;
}
