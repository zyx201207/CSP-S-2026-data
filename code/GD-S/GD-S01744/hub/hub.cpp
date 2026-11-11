#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int c,T,n,k,x,y,l,r,md,d[N],f1[N],f2[N];
int fa[N],dfn[N],sz[N],cnt,dt[N];
bool v[N];
vector<int>g[N];
queue<int>q;
void dfs(int x){
	dfn[x]=++cnt,sz[x]=1;
	for(int y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
		sz[x]+=sz[y];
	}
}
void gt(int x){
	dt[x]=1;
	for(int y:g[x])if(y!=fa[x]&&!v[y]){
		gt(y);
		dt[x]=max(dt[x],dt[y]+1);
	}
}
bool anc(int x,int y){return dfn[x]<=dfn[y]&&dfn[y]<dfn[x]+sz[x];}
void sol(int x){
	int mx=0,mn=1e9;
	for(int y:g[x])if(y!=fa[x]){
		sol(y);
		mx=max(mx,f1[y]+1),mn=min(mn,f2[y]+1);
	}
	f1[x]=mx,f2[x]=mn;
	if(mx+mn<=md)f1[x]=0;
	if(mx==md)cnt++,f1[x]=f2[x]=0;
}
bool chk(){
	if(k==2){
		cnt=0;
		sol(1);
		if(f1[1])cnt++;
		return cnt<3;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=1;l<=n;l++)d[l]=1e9;
			d[i]=d[j]=0;
			q.push(i);
			q.push(j);
			while(q.size()){
				x=q.front();
				q.pop();
				for(int y:g[x]){
					if(d[y]>d[x]+1){
						d[y]=d[x]+1;
						q.push(y);
					}
				}
			}
			bool fl=1;
			for(int l=1;l<=n;l++){
				if(anc(i,l)||anc(j,l))continue;
				if(d[l]>md){
					fl=0;
					break;
				}
				dt[l]=0;
			}
			if(!fl)continue;
			v[i]=v[j]=1;
			gt(i),gt(j);
			int s=2;
			for(int l=1;l<=n;l++){
				if(i==l||j==l)continue;
				s+=dt[l]>md;
			}
			v[i]=v[j]=0;
			if(s<=k)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x); 
		}
		cnt=0;
		dfs(1);
		l=0,r=n;
		while(l<r){
			md=(l+r)/2;
			if(chk())r=md;
			else l=md+1;
		}
		cout<<l<<'\n';
	}
}
