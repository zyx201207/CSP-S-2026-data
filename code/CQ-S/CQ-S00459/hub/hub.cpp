#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int C,T;
int n,k;
vector<int> v[N+5];
int pre[N+5];
void dfs(int x){
	for(int i:v[x]){
		if(i==pre[x]) continue;
		pre[i]=x;
		dfs(i);
	}
}
//
int rt1,rt2;
int f[N+5],maxn[N+5],maxn2[N+5];
void dfs2(int x,int fa,int p){
	if(x==0) return ;
	f[x]=1;
	maxn[x]=1;
	maxn2[x]=0;
	for(int i:v[x]){
		if(i==fa) continue;
		if(x==rt1&&i==rt2) continue;
		if(x==rt2&&i==rt1) continue;
		dfs2(i,x,p);
		if(maxn[i]>p) f[x]+=f[i];
		if(maxn[x]<maxn[i]+1){
			maxn2[x]=maxn[x];
			maxn[x]=maxn[i]+1;
		}
		else if(maxn2[x]<maxn[i]+1) maxn2[x]=maxn[i]+1;
	}
//	cout<<x<<" "<<fa<<" "<<f[x]<<" "<<maxn[x]<<'\n';
}
int sum[2];
void dfs3(int x,int fa,int p,int fmaxn,int fd,int t){
	if(x==0){
		sum[t]=0;
		return ;
	}
	if(maxn[x]<fmaxn+1){
		maxn2[x]=maxn[x];
		maxn[x]=fmaxn+1;
	}
	else if(maxn2[x]<fmaxn+1) maxn2[x]=fmaxn+1;
	if(fmaxn>p) f[x]+=fd;
//	cout<<"in "<<x<<" get "<<f[x]<<'\n';
	sum[t]=min(sum[t],f[x]);
	for(int i:v[x]){
		if(i==fa) continue;
		if(x==rt1&&i==rt2) continue;
		if(x==rt2&&i==rt1) continue;
		dfs3(i,x,p,(maxn[x]==maxn[i]+1?maxn2[x]:maxn[x]),f[x]-(maxn[i]>k?f[i]:0),t);
	}
}
bool chk(int x){
	for(int i=1;i<=n;i++){
		rt1=i;
		rt2=pre[i];
		sum[0]=n;
		sum[1]=n;
		dfs2(i,0,x);
		dfs3(i,0,x,0,0,0);
		dfs2(pre[i],0,x);
		dfs3(pre[i],0,x,0,0,1);
//		cout<<"chk "<<x<<" "<<i<<" "<<pre[i]<<" "<<sum[0]<<" "<<sum[1]<<'\n'; 
		if(sum[0]+sum[1]<=k) return 1;
	}
	return 0;
}
//
int id;
int sz[N+5];
void dfs4(int x,int fa){
	sz[x]=1;
	int maxn=0;
	for(int i:v[x]){
		if(i==fa) continue;
		dfs4(i,x);
		sz[x]+=sz[i];
		maxn=max(maxn,sz[i]);
	}
	maxn=max(maxn,n-sz[x]);
	if(maxn*2<=n) id=x;
}
bool chk2(int x){
	for(int i:v[id]){
		rt1=id;
		rt2=i;
		sum[0]=n;
		sum[1]=n;
		dfs2(id,0,x);
		dfs3(id,0,x,0,0,0);
		dfs2(i,0,x);
		dfs3(i,0,x,0,0,1);
		if(sum[0]+sum[1]<=k) return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		int x,y;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(C<=10){
			dfs(1);
			int l=1,r=n-1,ans=n-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(chk(mid)){
					r=mid-1;
					ans=mid;
				}
				else l=mid+1;
			}
			cout<<ans<<'\n';
		}
		else{
			id=0;
			dfs4(1,0);
			int l=1,r=n-1,ans=n-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(chk2(mid)){
					r=mid-1;
					ans=mid;
				}
				else l=mid+1;
			}
			cout<<ans<<'\n';
		}	
	}
	return 0;
}
