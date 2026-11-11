#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n,k;
vector<int>e[MAXN];
int dep[MAXN],dep2[MAXN],dep3[MAXN],dep4[MAXN],fat[MAXN],ff[21][MAXN];
pair<int,int>tmp[21][MAXN*2];
int st[MAXN],tot;
int lg2[MAXN*2];
int lca(int u,int v){
//	cerr<<'!'<<u<<' '<<v<<' '<<st[u]<<' '<<st[v]<<':';
	u=st[u],v=st[v];
	if(u>v)swap(u,v);
	int t=lg2[v-u+1];
	auto f=min(tmp[t][u],tmp[t][v-(1<<t)+1]).second;
//	cerr<<f<<'\n';
	return f;
}
int kfa(int u,int k){
	for(int j=20;j>=0;--j)if(k&(1<<j))u=ff[j][u];
	return u;
}
int dis(int u,int v){
	int f=lca(u,v);
	return dep[u]+dep[v]-2*dep[f];
}
void dfs(int u,int fa){
//	cerr<<u<<'\n';
	dep2[u]=dep3[u]=dep4[u]=0;
	for(auto v:e[u])if(v!=fa){
		dep[v]=dep[u]+1;
		fat[v]=u;
		ff[0][v]=u;
		tmp[0][++tot]=make_pair(dep[v],v);
		if(!st[v])st[v]=tot;
		dfs(v,u);
		tmp[0][++tot]=make_pair(dep[u],u);
		if(!st[u])st[u]=tot;
		if(1+dep2[v]>dep2[u]){
			dep4[u]=dep3[u];
			dep3[u]=dep2[u];
			dep2[u]=1+dep2[v];
		}
		else{
			if(1+dep2[v]>dep3[u]){
				dep4[u]=dep3[u];
				dep3[u]=1+dep2[v];
			}
			else dep4[u]=max(dep4[u],1+dep2[v]);
		}
	}
}
int ans=n;
int f[MAXN],top[MAXN];
void dfs2(int u,int fa,int mx){
	int c=0;
	for(auto v:e[u])if(v!=fa){
		dfs2(v,u,mx);
		c+=(dep2[v]>=mx);
	}
	if(!c){
		f[u]=1;
		top[u]=u;
	}
	else if(c==1){
		int mx2=0;
		for(auto v:e[u])if(v!=fa){
			if(dep2[v]>=mx){
				f[u]=f[v];
				top[u]=top[v];
			}
			else{
				mx2=max(mx2,1+dep2[v]);
			}
		}
		while(dep[top[u]]-dep[u]+mx2>mx){
			++f[u];
			top[u]=fat[top[u]];
		}
	}
	else{
		top[u]=u;
		f[u]=1;
		for(auto v:e[u])if(v!=fa){
			if(dep2[v]>=mx){
				f[u]+=f[v]+(dep[top[v]]-dep[v]);
			}
		}
	}
}
void dfs3(int u,int fa,int mx,int g,int tp,int d2){
//	cerr<<u<<' '<<fa<<' '<<mx<<' '<<g<<' '<<tp<<' '<<d2<<':'<<f[u]<<' '<<top[u]<<':'<<(max(g,1)+max(f[u],1))<<'\n';
	ans=min(ans,max(g,1)+max(f[u],1));
	int c=(d2>=mx),s=0;
	if(d2>=mx)s+=g+dis(tp,u)-1;
	int lst=-1,lst2=-1;
	for(auto v:e[u])if(v!=fa){
		c+=(dep2[v]>=mx);
		if(dep2[v]>=mx){
			if(lst==-1)lst=v;
			else lst2=v;
		}
		s+=f[v]+(dep[top[v]]-dep[v]);
	}
	for(auto v:e[u])if(v!=fa){
		c-=(dep2[v]>=mx);
		s-=f[v]+(dep[top[v]]-dep[v]);
		int d3=(1+dep2[v]==dep2[u]?dep3[u]:dep2[u]);
		int ndp=1+max(d2,d3);
//		cerr<<u<<" -> "<<v<<':'<<c<<' '<<d3<<' '<<ndp<<'\n';
		if(!c){
			dfs3(v,u,mx,1,u,ndp);
		}
		else if(c==1){
			if(d2>=mx){
				int k=mx-d3;
				auto f=lca(tp,u),di=dep[tp]+dep[u]-2*dep[f];
//				cerr<<tp<<' '<<u<<' '<<f<<'\n';
				if(di<=k){
					dfs3(v,u,mx,g,tp,ndp);
				}
				else{
					if(f==tp){
						auto nd=kfa(u,k);
						dfs3(v,u,mx,g+di-k,nd,ndp);
					}
					else{
						auto newd=di-k;
						if(dep[tp]-dep[f]>=newd){
							dfs3(v,u,mx,g+newd,kfa(tp,newd),ndp);
						}
						else{
							dfs3(v,u,mx,g+newd,kfa(u,k),ndp);
						}
					}
				}
			}
			else{
				int vv=(lst==v?lst2:lst);
				int dp=max(d2,dep4[u]);
				for(int d:{dep2[u],dep3[u]}){
					if(d!=1+dep2[v]&&d!=1+dep2[vv]){
						dp=max(dp,d);
						break;
					}
				}
				int tp=top[vv],tg=f[vv];
				if(dep[tp]-dep[u]+dp<=mx){
					dfs3(v,u,mx,tg,tp,ndp);
				}
				else{
					int tt=dep[tp]-dep[u]+dp-mx;
					dfs3(v,u,mx,tg+tt,kfa(tp,tt),ndp);
				}
			}
		}
		else if(c==2){
			dfs3(v,u,mx,s,u,ndp);
		}
		s+=f[v]+(dep[top[v]]-dep[v]);
		c+=(dep2[v]>=mx);
	}
}
bool check(int mx){
//	cerr<<':'<<mx<<'\n';
	dfs2(1,0,mx);
	ans=f[1];
	dfs3(1,0,mx,0,0,0);
	return ans<=k;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		e[i].clear();
		st[i]=0;
	}
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	tot=0;
	dfs(1,0);
	for(int j=1;j<21;++j){
		for(int i=1;i<=n;++i){
			ff[j][i]=ff[j-1][ff[j-1][i]];
		}
		for(int i=1;i+(1<<j)-1<=tot;++i){
			tmp[j][i]=min(tmp[j-1][i],tmp[j-1][i+(1<<(j-1))]);
		}
	}
	for(int i=2;i<=tot;++i)lg2[i]=lg2[i>>1]+1;
	int l=0,r=n,mid;
	while(r-l>1){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)solve();
}
