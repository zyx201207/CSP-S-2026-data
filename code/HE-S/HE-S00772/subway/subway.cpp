#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=501,M=5e5+1,Inf=0x3f3f3f3f3f3f3f3f;
__inline void read(int&x){
	char ch=getchar();
	x=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return;
}
__inline void write(int x){
	if(x>=10){
		write(x/10);
		x%=10;
	}
	putchar(x^48);
	return;
}
__inline void writeln(int x){
	write(x);
	putchar('\n');
	return;
}
int Id,n,m,d,q,addv[M],dis[N][N];
vector<array<int,2> >lines[M];
string program(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(0);
	memset(dis,0x3f,sizeof(dis));
	read(Id),read(n),read(m),read(d),read(q);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
		read(addv[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int p,t;k;k--){
			read(p),read(t);
			for(auto ed:lines[p]){
				int v=ed[0],w=ed[1];
				dis[i][v]=min(dis[i][v],w+t);
			}
			lines[p].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int ds=min(dis[i][j],dis[j][i]);
			dis[i][j]=dis[j][i]=ds;
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int u,v,ans;q;q--){
		read(u),read(v);
		ans=Inf;
		for(auto eu:lines[u])
			for(auto ev:lines[v])
				ans=min(ans,eu[1]+dis[eu[0]][ev[0]]+ev[1]);
		writeln(addv[u]+ans+addv[v]);
	}
	return"H17"; 
}
string H17=program();
signed main(){
	return 0;
}
