#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x; 
}
const int N=5e5+55,D=25+55;
const ll inf=1e18;
int n,m;
ll w[N];
int d,q;
int b[N][25],lb[N];
ll hf[N][25];
//经过x的所有线路编号，以及花费时间 
int L[505],R[505];//这条线路的范围
int a[N];
ll ti[N];
//地铁站编号，花费时间 
ll f[505][505];//最短路
void re(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=inf;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int x=1;x<=n;x++){
		for(int i=L[x];i<=R[x];i++){
			int nw=a[i];
			for(int j=1;j<=lb[nw];j++){
				int y=b[nw][j];
				//站台 -> 站厅 -> 站台
				f[x][y]=min(f[x][y],ti[i]+hf[nw][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
//	system("fc subway7.ans subway.out"); return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int le=read();
		L[i]=R[i-1]+1;
		R[i]=R[i-1]+le;
		for(int j=L[i];j<=R[i];j++){
			a[j]=read();
			ti[j]=read();
			int nw=a[j];
			lb[nw]++; 
			b[nw][lb[nw]]=i;
			hf[nw][lb[nw]]=ti[j];
		}
	}
	re();
	while(q--){
		int x=read(),y=read();
		ll ans=inf;
		for(int i=1;i<=lb[x];i++){
			for(int j=1;j<=lb[y];j++){
				int t1=b[x][i],t2=b[y][j];
				//地铁口 -> 站厅 -> 站台... -> 站厅 -> 地铁口 
				ans=min(ans,f[t1][t2]+w[x]+w[y]+hf[x][i]+hf[y][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
q次询问,x走到y
先从地铁口走到站厅内
然后，从该站厅走到该线路站台
图论建模
f[x][y]表示从线路x，走到线路y，的最短路
在线路x，可以通过一直免费走，走到需要到的站台p
然后走到站厅，从而走到另一条线路
1.预处理：
枚举线路x，和线路x上的每个站台p
然后，枚举经过p的所有d个线路 
复杂度\sum k[i]*d = 5e5*20
得出f[x][y]表示只通过换乘1次，的最短路
floyd一下
 
2.查询：
枚举经过x的所有d个线路，以及经过y的所有d个线路
q*d*d=1e5*20*20
总复杂度：
\sumk[i]*d+n^3+q*d*d 
*/ 
