#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=1e6+10;
int n,k,dis1[N],dis2[N],dis3[N],S,U,dep[N],ma[N],f[N],ma2[N],f2[N],dep2[N];
bool vis[N],fl[N];
vector<int> e[N],v;

void dfs(int u,int fa,int dis[]){
	for(int v:e[u])if(v!=fa){
//		cout<<u<<" "<<v<<" "<<dis[u]<<endl;
		dis[v]=dis[u]+1;
		dfs(v,u,dis);
	}
}

void dfs_(int u,int fa,int x){
	if(vis[u])dep[u]=0;
	else dep[u]=dep[fa]+1;
	ma[u]=dep[u];
	for(int v:e[u]){
		if(v==fa)continue;
		dfs_(v,u,x);
		ma[u]=max(ma[u],ma[v]);
//		f[u]+=f[v]; 
	}
//	if(f[u])f[u]++;
//	if(ma[u]==dep[u]+x)f[u]=1;
}

void dfs__(int u,int fa,int x){
	if(vis[u])dep2[u]=0;
	else dep2[u]=dep2[fa]+1;
	ma2[u]=dep2[u];
	for(int v:e[u]){
		if(v==fa)continue;
		dfs__(v,u,x);
		ma2[u]=max(ma2[u],ma2[v]);
//		f2[u]+=f2[v]; 
	}
//	if(f2[u])f2[u]++;
//	if(ma2[u]==dep2[u]+x)f2[u]=1;
}

void dfs2(int u,int fa,int x){
	for(int v:e[u]){
		if(v==fa||fl[v])continue;
		dfs2(v,u,x);
		f[u]+=f[v];
	}
	if(f[u]&&!vis[u])f[u]++;
	if(ma[u]==dep[u]+x&&!vis[u])f[u]=1;
}

bool check(int x){
	int l=x,r=dis2[U]-x;
	for(int i=0;i<=min(r-l,k-2);++i){
		for(int j=0;j<=min(r-l-i-1,k-i-2);++j){
			for(int t=1;t<=n;++t)vis[t]=ma[t]=f[t]=dep[t]=0;
			int p=i+l,q=r-j;
			for(int t=l;t<=p;++t)vis[v[t]]=1;
			for(int t=q;t<=r;++t)vis[v[t]]=1;
			dfs_(v[p],0,x);
			dfs__(v[q],0,x);
//			for(int t=1;t<=n;++t)cout<<ma[t]<<" ";
//			cout<<endl; 
//			for(int t=1;t<=n;++t)cout<<dep[t]<<" ";
//			cout<<endl;
//			for(int t=1;t<=n;++t)cout<<ma2[t]<<" ";
//			cout<<endl; 
//			for(int t=1;t<=n;++t)cout<<dep2[t]<<" ";
//			cout<<endl; 
			bool flg=0;
			for(int t=1;t<=n;++t)if(min(dep[t],dep2[t])>x){
				flg=1;
				break;
			}
			if(flg)continue;
			for(int t=l;t<=p;++t)dfs2(v[t],0,x);
			for(int t=q;t<=r;++t)dfs2(v[t],0,x);
//			for(int t=1;t<=n;++t){
//				dep[t]=min(dep[t],dep2[t]);
//				ma[t]=min(ma[t],ma2[t]);
//			}
//			dfs___(v[p],0,x);
			int ans=0;
			for(int t=l;t<=p;++t)ans+=f[v[t]];
			for(int t=q;t<=r;++t)ans+=f[v[t]];
//			cout<<x<<" "<<p<<" "<<q<<":"<<endl;
//			for(int t=1;t<=n;++t)cout<<f[t]<<" ";
//			cout<<endl; 
			if(ans+i+j+2<=k)return 1;
		}
	}
	return 0;
}

bool check2(int x){
	if(4*x+k-2>=dis2[U]+1)return 1;
	else return 0;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			e[i].clear();
			dis1[i]=dis2[i]=dis3[i]=0x3f3f3f3f3f3f3f3f;
			fl[i]=0;
		}
		v.clear();
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dis1[1]=0;
		dfs(1,0,dis1);
		S=1;
		for(int i=2;i<=n;++i)if(dis1[i]>dis1[S])S=i;
		dis2[S]=0;
		dfs(S,0,dis2);
		U=1;
		for(int i=2;i<=n;++i)if(dis2[i]>dis2[U])U=i;
		dis3[U]=0;
		dfs(U,0,dis3);
//		for(int i=1;i<=n;++i){
//			cout<<i<<" "<<dis1[i]<<" "<<dis2[i]<<" "<<dis3[i]<<endl;
//		}
		for(int i=1;i<=n;++i)if(dis2[i]+dis3[i]==dis2[U]){
			v.push_back(i);
			fl[i]=1;
		}
		sort(v.begin(),v.end(),[&](int x,int y){return dis2[x]<dis2[y];});
//		cout<<S<<" "<<U<<endl;
//		cout<<endl;
		if(C<=7||C==11||C==12||C==15){
			int l=0,r=dis2[U]/2-1,ans=dis2[U]/2;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid))ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<ans<<endl;
		}else if(C==13||C==14){
			if(n==k)cout<<"0"<<endl;
			else{
				int l=0,r=dis2[U]/2-1,ans=dis2[U]/2;
				while(l<=r){
					int mid=l+r>>1;
					if(check2(mid))ans=mid,r=mid-1;
					else l=mid+1;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

