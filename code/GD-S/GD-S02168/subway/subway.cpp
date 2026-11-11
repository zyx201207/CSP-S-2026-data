#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0x7fffffff,t[505][250005],ne[505][250005],w[2500005];
int di[2500005];
vector<int> x[2500005];
//void bfs(int start,int end){
//	queue<int> p;
//	p.push(start);
//	while(p.size()){
//		int o=p.front();
//		p.pop();
//		if(o==end){
//			ans=min(ans,d[o]);
//		}
//		for(int i=0;i<a[o].size();i++){
//			int oo=g[o][i];
//			d[oo]=min(d[oo],d[o])
//		}
//	}
//}
void dfs(int start,int now,int end,int lin,int la){
	if(now==end){
		ans=min(ans,la+t[lin][now]);
	}
	for(int i=0;i<x[now].size();i++){
		if(now==start){
			di[now]=t[x[now][i]][now];
		}else{
			di[now]=t[lin][now]+t[x[now][i]][now]+la;
		}
		dfs(start,ne[i][now],end,x[now][i],di[now]);
		di[now]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int aa,ss;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			if(j==1) aa=a;
			else ss=a;
			t[i][a]=b;
			x[a].push_back(i);
		//	g[a].push_back({i,})
		}
		ne[i][aa]=ss;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		memset(di,127,sizeof(di));
		ans=0x7fffffff;
		dfs(l,l,r,0,0);
		cout<<ans+w[l]+w[r]<<endl;
	}
	return 0;
}
