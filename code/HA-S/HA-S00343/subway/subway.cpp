#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st,en,sumk;
long long w[10005],a[205][405],t[205][405],cst[205][405],ans=1e18,to[200005],nxt[200005],h[20005],cnt,blon[200005];
void add(int a,int b,int c){
	to[++cnt]=b;
	blon[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
void dfs(int u,int fa,int prek,long long dis){
	for(int i=h[u];i;i=nxt[i]){
		int v=to[i],nowk=blon[i];
		if(v==fa) continue;
		if(u==st) dis=w[st]+cst[nowk][st];
		if(nowk==prek){
			if(v==en){
				ans=min(ans,dis+w[en]+cst[nowk][en]);
			}
			else dfs(v,u,nowk,dis);
		}else{
			if(v==en){
				ans=min(ans,dis+w[en]+cst[nowk][en]+cst[prek][u]+cst[nowk][u]);
			}
			else dfs(v,u,nowk,dis+cst[prek][u]+cst[nowk][u]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		sumk+=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			cst[i][a[i][j]]=t[i][j];
			if(j>1){
				add(a[i][j-1],a[i][j],i);
				add(a[i][j],a[i][j-1],i);
			}
		}
	}
	if(n<=3&&sumk<10){
		while(q--){
			ans=1e18;
			cin>>st>>en;
			dfs(st,0,blon[h[st]],0);
			cout<<ans<<"\n";
		}
	}else{
		while(q--){
			cin>>st>>en;
			cout<<w[st]+w[en]+cst[st][blon[h[st]]]+cst[en][blon[h[en]]]<<"\n";
		}
	}
	return 0;
}
