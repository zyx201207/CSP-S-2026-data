#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,num,ans;
int f[25];
int dep[25];
int bz[25][25];
bool flag[25];
bool ok[25][25];
vector<int> v[25];
void dfs(int x,int s,int fa){
	dep[x]=s;
	for(auto ch:v[x]){
		if(ch==fa) continue;
		bz[ch][0]=x;
		dfs(ch,s+1,x);
	}
}
int fnd(int x){
	if(f[x]==x) return x;
	return f[x]=fnd(f[x]);
}
void un(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(fx==fy) return;
	f[fx]=fy;
	--num;
}
int lca(int x,int y){
	int res=0;
	if(dep[x]>dep[y])
		for(int i=20;i>=0;i--) if(bz[x][i]&&dep[bz[x][i]]>=dep[y]) x=bz[x][i],res+=(1<<i);
	if(dep[x]<dep[y])
		for(int i=20;i>=0;i--) if(bz[y][i]&&dep[bz[y][i]]>=dep[x]) y=bz[y][i],res+=(1<<i);
	for(int i=20;i>=0;i--) if(bz[x][i]!=bz[y][i]) x=bz[x][i],y=bz[y][i],res+=2*(1<<i);
	if(x!=y) res+=2;
	return res;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e18;
		memset(ok,false,sizeof(ok));
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			ok[x][y]=ok[y][x]=true;
		}
		dfs(1,0,0);
		for(int j=1;j<=20;j++)
			for(int i=1;i<=n;i++) bz[i][j]=bz[bz[i][j-1]][j-1];
		for(int i=0;i<(1<<n);i++){
			num=k;
			int sum=0;
			for(int j=1;j<=n;j++) flag[j]=false,f[j]=j;
			for(int j=0;j<n;j++) if(i&(1<<j)) flag[j+1]=true,++sum;
			if(sum!=k) continue;
			for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++) if(flag[j]&&flag[k]&&ok[j][k]) un(j,k);
			if(num>2) continue;
			int s=0;
			for(int i=1;i<=n;i++){
				int nu=1e18;
				for(int j=1;j<=n;j++) if(flag[j]) nu=min(nu,lca(i,j));
				s=max(s,nu);
			}
			ans=min(ans,s);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
