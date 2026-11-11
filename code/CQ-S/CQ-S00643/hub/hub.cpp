#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool fl[N];
int op,T,n,k,x,y,s,cnt,ans,b[N],f[N];
struct node{
	int da,nx;
}a[2*N];
void add(int x,int y){
	a[++cnt]={y,b[x]};
	b[x]=cnt;
}
void chk(int x,int fa){
	if(!fl[fa]&&fl[x]) ++s;
	if(fl[x]) f[x]=0;
	for(int i=b[x];i;i=a[i].nx){
		int y=a[i].da;
		if(y==fa) continue;
		chk(y,x);
		f[x]=min(f[x],f[y]+1);
	}
}
void dfss(int x,int fa){
	if(fa) f[x]=min(f[x],f[fa]+1);
	for(int i=b[x];i;i=a[i].nx){
		int y=a[i].da;
		if(y==fa) continue;
		dfss(y,x);
	}
}
void dfs(int x,int y){
	if(y==k){
		s=0;
		for(int i=1;i<=n;++i){
			f[i]=1e9;
		}
		chk(1,0);
		if(s>2) return;
		dfss(1,0);
		int mx=0;
		for(int i=1;i<=n;++i){
			mx=max(mx,f[i]);
		}
		ans=min(ans,mx);
		return;
	}
	if(x>n) return;
	fl[x]=1;
	dfs(x+1,y+1);
	fl[x]=0;
	dfs(x+1,y);
}
void solve(){
	cin>>n>>k;
	cnt=0,ans=1e9;
	for(int i=1;i<=n;++i){
		fl[i]=b[i]=0;
	}
	for(int i=1;i<n;++i){
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>op>>T;
	while(T--) solve();
	return 0;
}
