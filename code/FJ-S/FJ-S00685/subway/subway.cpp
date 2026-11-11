#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+1;
struct str{
	long long x,y;
}z;
vector<str> v[N],u[M];
long long c,n,m,d,q,k[N],w[M],h[N][N];
int xz(int xl){
	int l=0,r=k[xl],md;
	while(l<r){
		md=l+r>>1;
		if(v[xl][md].x<z.y) l=md+1;
		else if(v[xl][md].x>z.y) r=md-1;
		else{
			r=md;
			break;
		}
	}
	return r;
}
long long dfs(int xl,long long s){
	long long mn=1e18;
	for(int i=1;i<=n;i++){
		int r=xz(i);
		if(r<k[i]&&v[i][r].x==z.y) mn=min(mn,s+h[i][xl]+v[i][r].y);
	}
	return mn;
}
int cmp(str l,str r){
	return l.x<r.x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) h[i][j]=1e18;
		h[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>z.x>>z.y;
			v[i].push_back(z);
			u[z.x].push_back({i,z.y});
		}
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=1;i<=m;i++) for(auto l:u[i]) for(auto r:u[i])
		if(l.x!=r.x) h[l.x][r.x]=h[r.x][l.x]=min(h[l.x][r.x],l.y+r.y);
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				h[i][j]=min(h[i][j],h[i][l]+h[l][j]);
	while(q--){
		long long mn=1e18;
		cin>>z.x>>z.y;
		for(auto l:u[z.x])
			mn=min(mn,dfs(l.x,l.y));
		printf("%lld\n",w[z.x]+mn+w[z.y]);
	}
	return 0;
}
