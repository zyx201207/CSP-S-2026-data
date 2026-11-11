#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=2e6+5;
int C,T,n,k,a,b,sz[N],fa[N],ans,f[N],st[N][25],cnt,dep[N];
vector<int>v[N];
bool vis[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	st[++cnt][0]=x;
	f[x]=cnt;
	for(auto y:v[x]){
		if(y==fa)continue;
		dfs(y,x);
		st[++cnt][0]=x; 
	}
}
int cp(int x,int y){
	if(f[x]<f[y])return x;
	return y;
}
int getlca(int x,int y){
	if(f[x]>f[y])swap(x,y);
	int num=log2(f[y]-f[x]+1);
	int len=1<<num;
	return cp(st[f[x]][num],st[f[y]-len+1][num]);
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[getlca(x,y)];
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void mix(int x,int y){
	if(sz[x]<sz[y])swap(x,y);
	sz[x]+=sz[y];
	fa[y]=x;
}
void solve(int x,int ct){
	if(ct>k)return;
	if(x>n){
		if(ct==k){
			int sc=ct;
			for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
			for(int i=1;i<=n;i++){
				for(auto y:v[i]){
					int a=i,b=y;
					if(vis[a]&&vis[b]){
						a=find(a),b=find(b);
						if(a!=b){
							mix(a,b);
							sc--;
						}
					}
				}
			}
			if(sc>2)return;
			int D=0;
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				int di=1e9;
				for(int j=1;j<=n;j++){
					if(!vis[j])continue;
					di=min(di,dis(i,j));
				}
				D=max(D,di);
			}
			ans=min(D,ans);
		}
		return;
	}
	vis[x]=1;
	solve(x+1,ct+1);
	vis[x]=0;
	solve(x+1,ct);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		ans=1e9;
		cnt=0;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1,0);
		for(int len=2;len<=cnt;len<<=1){
			int num=log2(len);
			for(int j=1;j+len-1<=cnt;j++){
				st[j][num]=cp(st[j][num-1],st[j+len/2][num-1]);
			}
		}
		if(k==1&&n>10){
			for(int i=1;i<=n;i++){
				int D=0;
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					D=max(D,dis(i,j));
				}
				ans=min(ans,D);
			}
			cout<<ans<<"\n";
			continue;
		} 
		if(k==2&&n>10){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int D=0;
					for(int z=1;z<=n;z++){
						if(z==i||z==j)continue;
						D=max(D,min(dis(i,z),dis(j,z)));
					}
					ans=min(D,ans);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		solve(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

