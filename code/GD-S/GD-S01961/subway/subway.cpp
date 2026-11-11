#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long c,n,m,d,q,w[M],a[M],t[M],cnt,fa[M],ans;
struct node{
	long long z,x,y;
}e[M],f[M];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
} 
void dfs(long long p,long long x){	
	if(f[p].x==x){
		ans+=f[p].z;
		return;
	}
	ans+=f[p].z;
	dfs(f[p].x,x);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		fa[i]=i;
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			for(int v=j+1;v<=k;v++){
				e[++cnt].x=a[j];
				e[cnt].y=a[v];
				e[cnt].z=t[j]+t[v];	
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	while(q--){
		int x,y;
		cin>>x>>y;
		long long cn=0;
		for(int i=1;i<=m;i++){
			fa[i]=i;	
		}
		for(int i=1;i<=cnt;i++){
			int xx=find(e[i].x),yy=find(e[i].y);
			f[e[i].y].x=e[i].x;
			f[e[i].y].z=e[i].z;
			if(xx!=yy){
				fa[xx]=yy;
				cn++;
			}
			if(cn==cnt-1)break;
		}
		ans=0;
		dfs(y,x);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
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

0 3 7 20 2 
8 3 6 1 7 2 9 
3 1 4 2 5 5 100 
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3
*/

