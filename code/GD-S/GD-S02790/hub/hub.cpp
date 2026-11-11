#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e4+7;
int c,t,n,k,dep[N],st[20][N],lg[N],ktp[N],lc[N][N];
bool okk[N];
set<pair<int,int>> cnt;
vector<int> changed;
vector<int> g[N];
vector<int> rea[N];
set<int> waiting;
void dfs(int x,int f){
	st[0][x]=f;
	dep[x]=dep[f]+1;
	for(auto &it:g[x]){
		int to=it;
		if(to==f) continue;
		dfs(to,x);
	}
}
int lca(int x,int y){
	int X=x,Y=y;
	if(lc[x][y]) return lc[x][y];
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]!=dep[y]){
		x=st[lg[dep[x]-dep[y]]][x];
	}
	if(x==y) return lc[X][Y]=x;
	for(int i=19;i>=0;i--){
		if(st[i][x]!=st[i][y]){
			x=st[i][x];
			y=st[i][y];
		}
	}
	return lc[X][Y]=st[0][x];
}
void init(){
	memset(st,0,sizeof(st));
	dfs(1,0);
	lg[1]=0;
	for(int i=2;i<=n;i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			st[i][j]=st[i-1][st[i-1][j]];
		}
	}
}
int dis(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
bool sele[N],vis[N];
void ds(int x){
	vis[x]=1;
	for(auto &it:g[x]){
		if(!vis[it]&&sele[it]){
			vis[it]=1;
			ds(it);
		}
	}
}
int getl(){
	int ctt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[i]&&sele[i]){
			ds(i);
			ctt++;
		}
	}
	return ctt;
}
set<pair<int,int>> nw;
void adj() {
	int ct=getl();
	if(ct<=2)  return;
	nw.clear();
	for(int i=1;i<=n;i++){
		if(!sele[i]){
			sele[i]=1;
			int tppp=getl();
			if(tppp<=2){
				auto tmp=*cnt.lower_bound({ktp[i],i});
				nw.insert(tmp);
			}
			sele[i]=0;
		}
	}
	cnt=nw;
}
bool check(int x){
	cnt.clear();
	for(int i=1;i<=n;i++) rea[i].clear(),ktp[i]=0,okk[i]=0,cnt.insert({0,i});
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			if(dis(i,j)<=x){
				auto tmp=*cnt.lower_bound({ktp[j],j});
				cnt.erase(tmp);
				ktp[j]++;
				cnt.insert({ktp[j],j});
				rea[i].push_back(j);
			}
		}
	}
	int ok=0;
	int sum=0;
	memset(sele,0,sizeof(sele));
	while(ok<n){
		auto tp=*cnt.rbegin();
		int idx=tp.second;
		cnt.erase(tp);
		sum++;
		sele[idx]=1;
		changed.clear();
//		adj();
		for(auto &to:rea[idx]){
			if(okk[to]==0) ok++,changed.push_back(to);
		}
		for(auto &to:changed){
			for(auto &TO:rea[to]){
				auto tmp=*cnt.lower_bound({ktp[TO],TO});
				if(tmp.second!=TO) continue;
				cnt.erase(tmp);
				ktp[TO]--;
				cnt.insert({ktp[TO],TO});
			}
		}
	}
	return sum<=k;
}

void spec(){
	if(k==2){
		init();
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				int maxx=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					maxx=max({maxx,min(dis(i,k),dis(j,k))});
				}
				minn=min(minn,maxx);
			}
		}
		printf("%d\n",minn);
		return;
	}
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(k<=2){
		spec();
		return;
	}
	memset(lc,0,sizeof(lc));
	init();
	int l=0,r=n,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",res);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
} 
