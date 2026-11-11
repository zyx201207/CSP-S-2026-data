#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
ll read(){
	ll k=0,f=1;
	int c=getchar();
	for(;!isdigit(c);c=getchar()){if(c=='-')f=-1;}
	for(;isdigit(c);c=getchar()){k=k*10+(c&15);}
	return f*k;
}
const int maxm=5e5+100,maxn=510;
ll c,n,m,d,q;
//m:地铁站数 
ll w[maxm];//从每个地铁站的地铁口走到站厅的时间 
//bool id[maxn][maxm];//这条线路有没有这个站
//ll t[maxn][maxm];//这个站到这个线路的 
vector<int>a[maxn];//每条线路所经过的站 
vector<pli>b[maxm];//每个站所连接的站及到那个站的代价 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		
	} 
	return 0;
}
