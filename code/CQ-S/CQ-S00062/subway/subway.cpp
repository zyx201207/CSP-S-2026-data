#include<bits/stdc++.h>
using namespace std;
struct node{
	int l[505];
	int t[505];
	int tot;
}p[500005];
int c,n,m,d,q,x,y,w[500005],a[500005],t[500005],ans=1e9;
void dfs(int st,int t){
	if(st==y){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=p[st].tot;i++){
		dfs(st+i,p[st].t[i]+t);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			p[j].l[++p[j].tot]=i;
			p[j].t[++p[j].tot]=t[j];
		}
	}
	while(q--){
		cin>>x>>y;
		dfs(x,0);
		ans+=w[x]+w[y];
	}
	cout<<ans;
	return 0;
}

