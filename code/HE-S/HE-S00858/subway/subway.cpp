#include<bits/stdc++.h>
#define ll long long
#define enter putchar('\n');
#define space putchar(' ');
using namespace std;
const int N=505,M=1e3+5,D=20;
ll read();
void write(ll x);
ll c,n,m,d,q,mp[M][M],w[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		mp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		ll k,a[D],t[D];
		k=read();
		for(int j=1;j<=k;j++){
			a[j]=read();
			t[j]=read();
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				mp[a[u]][a[v]]=mp[a[v]][a[u]]=min(mp[a[u]][a[v]],t[u]+t[v]);
			}
		}
	}
	for(int u=1;u<=m;u++){
		for(int v=u+1;v<=m;v++){
			for(int k=u;k<=v;k++){
				mp[u][v]=mp[v][u]=min(mp[u][v],mp[u][k]+mp[k][v]);
			}
		}
	}
	while(q--){
		int x,y;
		x=read();
		y=read();
		write(mp[x][y]+w[x]+w[y]);
		enter;
	}
	return 0;
}
ll read(){
	ll op=1,cnt=0;
	int c;
	c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') op*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return op*cnt;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
