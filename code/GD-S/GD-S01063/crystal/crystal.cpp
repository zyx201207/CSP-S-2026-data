#include<bits/stdc++.h>
#define N 500005
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot;
ll dis[N],vis[N];

void read(ll &x){
	x=0;int ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));return;
}

int check(ll x){
	for(ll i=1;i<=n-x+1;i++){
		int z=vis[i+x-1]-vis[i-1];
		if(dis[i+x-1]*x-z<=m) return 1;
	}return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(ll i=1;i<=n;i++) read(dis[i]);
	sort(1+dis,1+dis+n);
	for(ll i=1;i<=n;i++) vis[i]=vis[i-1]+dis[i];
	ll l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}wh(l-1);
	return 0;
}/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4

3845
3845

315275
315275
*/
