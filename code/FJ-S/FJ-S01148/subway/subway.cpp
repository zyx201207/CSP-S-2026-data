#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,dk,qs,w[N],da[N],ds[N];
struct node
{
	int nex,to,val; 
}a[2*N];
int h[N],hs;
inline void add(int x,int y,int z)
{
	hs++;
	a[hs].nex=h[x];
	a[hs].to=y;
	a[hs].val=z;
	h[x]=hs;
}
long long d[N];
priority_queue<pair<int,int> > q1;
inline long long dij(int s,int t)
{
	memset(d,0x3f3f3f,sizeof(d));
	d[s]=0;
	q1.push(make_pair(0,s));
	while(q1.size()){
		int x=q1.top().second;
		q1.pop();
		for(int i=h[x];i;i=a[i].nex){
			int y=a[i].to;
			if(d[y]>d[x]+a[i].val){
				d[y]=d[x]+a[i].val;
				q1.push(make_pair(-d[y],y));
			}
		}
	}
	return d[t];
}
int dep[N],f[N][21];
long long dis[N];
inline void dfs(int x,int fa)
{
	for(int i=h[x];i;i=a[i].nex){
		int y=a[i].to;
		if(y==fa)continue;
		dis[y]=dis[x]+a[i].val;
		dep[y]=dep[x]+1;
		f[y][0]=x;
		dfs(y,x); 
	}
	for(int k=1;k<=19;k++){
		f[x][k]=f[f[x][k-1]][k-1];
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int k=19;k>=0;k--){
		if(dep[f[x][k]]>=dep[y]){
			x=f[x][k];
		}
	}
	if(x==y){
		return x;
	}
	for(int k=19;k>=0;k--){
		if(f[x][k]!=f[y][k]){
			x=f[x][k];
			y=f[y][k];
		}
	}
	return f[x][0];
}
queue<pair<int,int> > q2;
bool b[N];
inline int bfs(int s,int t)
{
	while(q2.size())q2.pop(); 
	memset(b,1,sizeof(b));
	q2.push(make_pair(0,s));
	b[s]=0;
	while(q2.size()){
		int x=q2.front().second,z=q2.front().first;
		q2.pop();
		for(int i=h[x];i;i=a[i].nex){
			int y=a[i].to;
			if(y==t){
				return z+1; 
			}
			if(b[y]){
				b[y]=0;
				q2.push(make_pair(z+1,y));
			}
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>dk>>qs;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>da[j]>>ds[j];
			for(int l=1;l<j;l++){
				add(da[l],da[j],ds[l]+ds[j]);
				add(da[j],da[l],ds[l]+ds[j]);
			}
		}
	}
	if(7<=c&&c<=11){
		dfs(1,0);
		while(qs--){
			int s,t;
			cin>>s>>t;
			cout<<dis[s]-dis[LCA(s,t)]+dis[t]+w[s]+w[t]<<"\n";
		}
	}
	else if(12<=c&&c<=19){
		while(qs--){
			int s,t;
			cin>>s>>t;
			cout<<bfs(s,t)*a[1].val+w[s]+w[t]<<"\n";
		}
	}
	else{
		while(qs--){
			int s,t;
			cin>>s>>t;
			cout<<dij(s,t)+w[s]+w[t]<<"\n";
		}
	}
	return 0; 
}
