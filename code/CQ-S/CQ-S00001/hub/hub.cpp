#include<bits/stdc++.h>
//#define int long long
using namespace std;
int T,t,n,m,x,y,cnt,dep[1000001],head[1000001],del[1000001],jl,mx,son[1000001],chs[1000001],ans;
struct dcz{
	int nex,to;
}a[2000001];
void add(int x,int y){
	a[++cnt].nex=head[x];
	a[cnt].to=y;
	head[x]=cnt;
}
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>mx) jl=u,mx=dep[u];
//	cout<<u<<" "<<dep[u]<<' '<<jl<<" "<<mx<<'\n';
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(v==fa||del[v]) continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>=mx) jl=u,mx=dep[u];
//	cout<<u<<" "<<dep[u]<<' '<<jl<<" "<<mx<<'\n';
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(v==fa||del[v]) continue;
		dfs2(v,u);
		if(dep[son[u]]<dep[v]) son[u]=v;
	}
}
void Dfs(int u,int fa){
//	cout<<"???\n";
	dep[u]=dep[fa]+1;
//	cout<<u<<" "<<dep[u]<<' '<<jl<<" "<<mx<<'\n';
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(v==fa||!chs[v]) continue;
		Dfs(v,u);
	}
}
void DFs(int u,int fa){
//	cout<<u<<" "<<dep[u]<<' '<<mx<<"\n";
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(v==fa||chs[v]) continue;
//		cout<<u<<" "<<v<<"\n";
		dep[v]=min(dep[v],dep[u]+1);
		DFs(v,u);
	}
}
void dfs(int wh,int k){
	if(k>m) return;
	if(wh==n+1){
		if(k!=m) return;
		int tot=0;
		for(int i=1;i<=n;i++) dep[i]=0;
		for(int i=1;i<=n;i++){
			if(!dep[i]&&chs[i]) Dfs(i,0),tot++;
		}
//		cout<<"!!!\n";
		if(tot>2) return;
		for(int i=1;i<=n;i++) dep[i]=INT_MAX;
		
		for(int i=1;i<=n;i++){
			if(chs[i]){
				dep[i]=0;
				DFs(i,0);
//				cout<<"!"<<jl<<' '<<mx<<"\n";
			}
		}
		mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,dep[i]);
		ans=min(ans,mx);
		return;
	}
	dfs(wh+1,k);
	chs[wh]=1;k++;
	dfs(wh+1,k);
	chs[wh]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y);add(y,x);
//			cout<<"!"<<x<<" "<<y<<"\n";
		}
		for(int i=1;i<=n;i++){
			for(int j=head[i];j;j=a[j].nex){
				int v=a[j].to;
//				cout<<"?"<<i<<" "<<v<<"\n";
			}
		}
		if(T<=3){
			ans=INT_MAX;
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else{
			dfs1(1,0);
			mx=0;
			dfs2(jl,0);
			cout<<mx/2<<"\n";
		}
	}
	return 0;
}
/*
题看错了是人类啊 
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

