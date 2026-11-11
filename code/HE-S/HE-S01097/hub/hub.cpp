#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,K,D,root,ans,d[N],dep[N],d2[N],son[N],fa[N],val[N],mx1[N][22],Fa[N][22],G[N][22],H[N][22];
int tot,top[N],dfn[N],id[N],Mx[N],lg[N];
int F[N],ID[N],MX[N];
vector<int> v[N];

int query1(int l,int r){
	int len=lg[r-l+1];
	return max(mx1[l][len],mx1[r-(1<<len)+1][len]);
}
void dfs1(int x,int faa){
	fa[x]=faa; dep[x]=dep[faa]+1;
	d[x]=son[x]=0; d2[x]=-1e9;
	for(auto y:v[x]){
		if(y==faa) continue;
		dfs1(y,x);
		if(d[y]+1>d[x]){
			d2[x]=d[x];
			d[x]=d[y]+1;
		}else{
			d2[x]=max(d2[x],d[y]+1);
		}
		if(d[y]>d[son[x]]) son[x]=y;
	}
}
void dfs4(int x,int faa){
	val[x]=0;
	for(auto y:v[x]){
		if(y==faa) continue;
		dfs4(y,x);
		val[x]+=val[y];
	}
	if(d[x]>=D) val[x]++;
}
void dfs3(int x,int ftop){
	top[x]=ftop;
	dfn[x]=++tot; id[tot]=x;
	Mx[ftop]=tot;
	if(son[x]) dfs3(son[x],ftop);
	for(auto y:v[x]){
		if(y==fa[x] || y==son[x]) continue;
		dfs3(y,y);
	}
}
void dfs2(int x,int faa){
	for(auto y:v[x]){
		if(y==faa) continue;
		dfs2(y,x);
	}
	if(x==root) return;
	
	int k=val[root]-val[x];
	
	int p=x;
	
	int l=dfn[x],r=Mx[top[x]];
	
	int mx=0-dfn[x];
	while(l<=r){
		int mid=(l+r)>>1;
		if(query1(dfn[x],mid)+mid>=D || mid-dfn[x]>=D) r=mid-1;
		else l=mid+1;
	}
//	while(son[p]){
//		mx=max(mx,d2[p]-dfn[p]);
//		if(mx+dfn[p]>=D) break;
//		p=son[p];
//	}
	k+=max(1,val[id[l]]);
	
	p=fa[x];
	int lst=x; mx=-dep[p];
	if(d[p]>=D){
		if(p!=root) mx=max(mx,(son[p]==lst?d2[p]:d[p])-dep[p]);
		
		if(n>1000){
			for(int i=21;i>=0;i--){
				if(dep[Fa[p][i]]<=5) continue;
				if(H[p][i]) continue;
				k-=(1<<i);
				mx=max(mx,G[p][i]);
				p=Fa[p][i];
			}	
		}
		
		while(p!=root){
			if(mx+dep[p]>=D) break;
			k--;
			if(fa[p]==root) break;
			mx=max(mx,G[p][0]);
			if(G[p][0]+dep[fa[p]]>D) break; 
			p=fa[p];
		}
		mx+=dep[p];
	}
	
//	if(D==2 && x==4) cerr<<x<<' '<<k<<' '<<p<<' '<<val[p]<<' '<<d2[fa[x]]<<endl;
	if(p==root){
		if(F[lst]){
			mx=max(mx,MX[lst]);
			p=ID[lst];
			mx-=dfn[p];
			
			int l=dfn[p],r=Mx[top[p]];
			
			while(l<=r){
				int mid=(l+r)>>1;
				if(query1(dfn[p],mid)-1+mid>=D || mx+mid>=D || d[fa[id[mid]]]<=D) r=mid-1;
				else l=mid+1;
			}
			k-=l-dfn[p];
			
//			while(d[fa[p]]>D){
//				if(mx+dfn[p]>=D) break;
//				k--;
//				mx=max(mx,d2[p]-dfn[p]-1);
//				p=son[p];
//			}
	//		if(D==178 && x==4802) cerr<<p<<' '<<d[fa[p]]<<' '<<k<<' '<<t+val[fa[p]]<<endl;
		}
	}
//	if(D==2 && k<=K) cerr<<x<<endl;
	ans=min(ans,k);
}
bool check(int x){
	D=x; ans=1e9;
	dfs4(root,0);
	if(val[root]<=K) return 1;
	
	vector<int> v2;
	int Mx1=0,Mx2=0;
	for(auto y:v[root]){
		if(d[y]+1>=D) v2.push_back(y);
		else{
			if(d[y]+1>Mx1){
				Mx2=Mx1;
				Mx1=d[y]+1;
			}else Mx2=max(Mx2,d[y]+1); 
		}
	}
	for(auto y:v[root]){
		F[y]=0;
		if(v2.size()-(d[y]+1>=D)==1){
			F[y]=1;
			if(d[y]+1>=D){
				for(auto k:v2) if(k!=y) ID[y]=k;
				MX[y]=Mx1;
			}else{
				ID[y]=v2.back();
				if(d[y]+1==Mx1) MX[y]=Mx2;
				else MX[y]=Mx1;
			}
		}
	}
	
//	if(D==2) cerr<<root<<endl<<val[root]<<endl;
	dfs2(root,0);
	return ans<=K;
}
signed main(){
//	system("fc hub.out hub.ans"); return 0;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T,x,y;
	cin>>T>>T;
	while(T--){
		cin>>n>>K;
		for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		//求直径，确定根
		queue<int> q;
		vector<int> dis,pre;
		for(int i=0;i<=n;i++) dis.push_back(n+1),pre.push_back(0);
		q.push(1); dis[1]=0;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(auto y:v[x]){
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
		}
		x=1;
		for(int i=1;i<=n;i++) if(dis[i]>dis[x]) x=i;
		for(int i=1;i<=n;i++) dis[i]=n+1;
		q.push(x); dis[x]=0;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(auto y:v[x]){
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					pre[y]=x;
					q.push(y);
				}
			}
		}
		x=1;
		for(int i=1;i<=n;i++) if(dis[i]>dis[x]) x=i;
		int t=dis[x]/2;
		for(int i=1;i<=t;i++) x=pre[x];
		root=x;
		
		dfs1(root,0);
		tot=0;
		dfs3(root,root);
		
		for(int i=1;i<=n;i++){
			mx1[i][0]=d2[id[i]]-i;
			Fa[i][0]=fa[i];
			G[i][0]=(son[fa[i]]==i?d2[fa[i]]:d[fa[i]])-dep[fa[i]];
			H[i][0]=(G[i][0]+dep[fa[i]]<=D);
		}
		for(int i=1;i<=21;i++){
			for(int j=1;j<=n;j++){
				mx1[j][i]=max(mx1[j][i-1],mx1[j+(1<<(i-1))][i-1]);
				Fa[j][i]=Fa[Fa[j][i-1]][i-1]; 
				G[j][i]=max(G[j][i-1],G[Fa[j][i-1]][i-1]);
				H[j][i]=H[j][i-1]+H[Fa[j][i-1]][i-1];
			}
		}
		
		int l=0,r=t;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		cout<<l<<'\n';
		
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}
