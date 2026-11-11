#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=500+5;
const int M=5e5+5;
//int cnt=0;
inline ll read(){
	//cnt++;
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-'),x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void solve();
int main(){
	if(ONLINE_JUDGE){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	else{
		freopen("subway7.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	int t=1;
	if(duoce)t=read();
	while(t--)solve();
}
int c,n,m,d,q;
ll w[M];
int ps[M][22];
ll pst[M][22];
int siz[M];
int x,y;
ll dist[N][N];
void solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dist[i][j]=0x3f3f3f3f3f3f3f3f;
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		int a;
		ll t;
		for(int j=1;j<=k;j++){
			a=read(),t=read();
			ps[a][++siz[a]]=i;
			pst[a][siz[a]]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=siz[i];j++){
			for(int k=1;k<j;k++){
				dist[ps[i][j]][ps[i][k]]=min(dist[ps[i][j]][ps[i][k]],pst[i][j]+pst[i][k]);
				dist[ps[i][k]][ps[i][j]]=dist[ps[i][j]][ps[i][k]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		x=read(),y=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=siz[x];i++){
			for(int j=1;j<=siz[y];j++){
				ans=min(ans,dist[ps[x][i]][ps[y][j]]+pst[x][i]+pst[y][j]);
			}
		}
		ans=ans+w[x]+w[y];
		write(ans);
		putchar('\n');
	}
}
/*
首先直接把每一个地铁站的d个都看一遍
结果是md^2的
fc D:\下午\subway\subway.out D:\下午\subway\subway7.ans
*/
