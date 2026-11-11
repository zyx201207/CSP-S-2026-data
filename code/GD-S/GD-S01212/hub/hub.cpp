#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
int n,m,k;
vector<int> e[N];
int mx1[N],mx2[N];
int s1[N],s2[N];
int d1[N],d2[N]; 
int lim1[N];
void dfs2(int u,int fa){
	mx1[u]=0;
	s1[u]=0,d1[u]=0;
	lim1[u]=k;
	for(int v:e[u])if(v!=fa)dfs2(v,u),mx1[u]=max(mx1[u],mx1[v]+1);
	if(mx1[u]<k)return;
	for(int v:e[u])if(v!=fa){
		if(s1[v]){
			if(s1[u]){
				s1[u]+=s1[v]+d1[v]+d1[u];
				d1[u]=0;
			}else{
				s1[u]=s1[v];
				d1[u]=d1[v]+1;
			}
		}else{
			lim1[u]=min(lim1[u],k-mx1[v]-1);
		}
	}
	if(!s1[u])s1[u]=1;
	if(lim1[u]<d1[u]){
		s1[u]+=d1[u]-lim1[u];
		d1[u]=lim1[u];
	}
}
int fs[N],fd[N],fmx[N],flim[N],gs[N],gd[N],gmx[N],glim[N];
int c[N];
void dfs3(int u,int fa){
	int len=0;
	for(int v:e[u])if(v!=fa)c[++len]=v;
	if(!len)return;
	
	gs[len+1]=gd[len+1]=gmx[len+1]=0;
	glim[len+1]=k;
	
	fmx[0]=mx2[u]+1;
	fs[0]=s2[u];
	if(s2[u]){
		fd[0]=d2[u]+1;
		flim[0]=k;
	}else{
		fd[0]=0;
		flim[0]=k-mx2[u]-1;
	}
	for(int i=1;i<=len;i++){
		int v=c[i];
		fd[i]=fd[i-1],fs[i]=fs[i-1],fmx[i]=fmx[i-1],flim[i]=flim[i-1];
		fmx[i]=max(fmx[i],mx1[v]+1);
		if(s1[v]){
			if(fs[i]){
				fs[i]+=s1[v]+d1[v]+fd[i];
				fd[i]=0;
			}else{
				fs[i]=s1[v];
				fd[i]=d1[v]+1;
			}
		}else{
			flim[i]=min(flim[i],k-mx1[v]-1);
		}
	}
	for(int i=len;i>=1;i--){
		int v=c[i];
		gd[i]=gd[i+1],gs[i]=gs[i+1],gmx[i]=gmx[i+1],glim[i]=glim[i+1];
		gmx[i]=max(gmx[i],mx1[v]+1); 
		if(s1[v]){
			if(gs[i]){
				gs[i]+=s1[v]+d1[v]+gd[i];
				gd[i]=0;
			}else{
				gs[i]=s1[v];
				gd[i]=d1[v]+1;
			}
		}else{
			glim[i]=min(glim[i],k-mx1[v]-1);
		}
	}
	for(int i=1;i<=len;i++){
		int mx=fmx[i-1],s=fs[i-1],d=fd[i-1],lim=flim[i-1];
		mx=max(mx,gmx[i+1]);
		lim=min(lim,glim[i+1]);
		if(gs[i+1]){
			if(s){
				s+=gs[i+1]+gd[i+1]+d;
				d=0;
			}else{
				s=gs[i+1];
				d=gd[i+1];
			}
		}else{
			lim=min(lim,k-gmx[i+1]);
		}
		mx2[c[i]]=mx;
		if(mx<k){
			s2[c[i]]=0;
			d2[c[i]]=0;
		}else{
			if(!s)s++;
			if(lim<d){
				s+=d-lim;
				d=lim;
			} 
			s2[c[i]]=s,d2[c[i]]=d;
		}
	}
	for(int v:e[u])if(v!=fa)dfs3(v,u);
}
bool check(int mid){
	k=mid;
	dfs2(1,0);
	s2[1]=d2[1]=0;
	mx2[1]=-1;
	dfs3(1,0);
	for(int i=2;i<=n;i++)if(max(s1[i],1)+max(s2[i],1)<=m)return true;
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(m==n){
		cout<<"0"<<endl;
		return;
	}
	int l=1,r=n-1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--)solve(); 
}

