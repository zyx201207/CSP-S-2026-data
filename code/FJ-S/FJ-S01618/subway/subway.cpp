#include<bits/stdc++.h>
using namespace std;
#define N 500005
int c,n,m,d,q;
int w[500005];
int la[1000005],nxt[1000005],fr[1000005],to[1000005],lu[1000005],f[1000005],el;
void ade(int u,int v,int t){
	el++;
	if(la[u]==0){
		f[u]=el;
	}
	nxt[la[u]]=el;
	la[u]=el;
	lu[el]=t;
	fr[el]=u;
	to[el]=v;
}
int k[505];
int vis[2*N];
long long mi;
struct node{
	int jd;
	long long jl;
}qq[N];
void ste(int s,int e){
	int h,t;
	h=t=1;
	qq[1].jd=s;
	qq[1].jl=0;
	vis[s]=0;
	while(h<=t){
		for(int j=f[qq[h].jd];j;j=nxt[j]){
			if(vis[to[j]]==-1||qq[h].jl+lu[j]<vis[to[j]]){
				t++;
				qq[t].jd=to[j];
				qq[t].jl=qq[h].jl+lu[j];
				vis[to[j]]=qq[h].jl+lu[j];
			}
			if(to[j]==e){
				mi=min(mi,qq[h].jl+lu[j]);
			}
		}
		h++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			ade(a,i+N,t);
			ade(i+N,a,t);
		}
	}
	
/*	for(int i=1;i<=el;i++){
		cout<<nxt[i]<<' '<<fr[i]<<' '<<to[i]<<' '<<lu[i]<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<la[i]<<endl;
	}
*/	while(q--){
		memset(vis,-1,sizeof(vis));
		int x,y;
		cin>>x>>y;
		mi=1e18;
		ste(x,y);
		cout<<mi+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 
 
期待CCF机子能多给点分 
 */
