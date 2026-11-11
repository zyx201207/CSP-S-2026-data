#include<bits/stdc++.h>//1 n 500  1 d 20  1 q 1e5
using namespace std;
#define ll long long
const int N=5e3+5;
ll c,n,m,d,q,a[N][N],t[N][N],w[N],k[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}//n 地铁线路数  m 地铁站数  d 每个地铁站最多被几条线路经过
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	while(q--){
		int x,y;
		x=read();y=read();
		ll ans=1e18;
		for(int i=1;i<=n;i++){
			int ok=0;
			for(int j=1;j<=m;j++) if(a[j][i]==x||a[j][i]==y) ok++;
			if(ok==2) ans=min(ans,t[i][x]+t[i][y]);
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}//小R：我该在哪里停留？我问我自己 
//17:52 样例解释有误说是 
//18:08 谁搁着玩小恐龙呢？！ 没绷住 
//期望得分0pts
