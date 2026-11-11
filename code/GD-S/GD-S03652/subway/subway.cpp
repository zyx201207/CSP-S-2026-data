#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e5+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0' ;
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
struct edge{
	int w,u;
};
vector<edge>v[N];
int a[N];
ll dist[505][505];
void solve(){
	int c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dist[i][j]=1e18;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++){
		dist[i][i]=0;
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),y=read();
			v[x].push_back({y,i});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++){
				int To1=v[i][j].u,To2=v[i][k].u;
				dist[To1][To2]=dist[To2][To1]=min(dist[To1][To2],0ll+v[i][j].w+v[i][k].w);
			}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//	cout<<dist[1][2];
	for(int i=1;i<=q;i++){
		int X=read(),Y=read();ll minn=1e18;
		for(int j=0;j<v[X].size();j++)
			for(int k=0;k<v[Y].size();k++)
				minn=min(minn,dist[v[X][j].u][v[Y][k].u]+v[X][j].w+v[Y][k].w);
		write(minn+a[X]+a[Y]);
		puts("");
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
