#include<bits/stdc++.h>
#define N 2000005
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot;
ll dis[N],vis[N],wis[N],f[N];
unordered_map<ll,ll> kis,g;

void read(ll &x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);//miss 
	read(jk),read(jk);while(jk--){
		read(n),read(k);
		for(int i=1;i<=n;i++) read(dis[i]),wis[i]=0;
		for(ll i=1;i<=n;i++){
			ll l=i,r=n,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(dis[mid]-dis[i]<=k) l=mid+1;
				else r=mid-1;
			}vis[i]=l-1;
		}
		for(ll i=n;i>=1;i--){
			kis=g;
			ll r=i;f[i]=0;kis[0]++;
			for(ll j=i-1;j>=1;j--){
				if(vis[j]<=j) break;
				f[j]=f[min(vis[j],(ll)i)]+1;
				while(r>vis[j])	--kis[f[r]],r--;
				if((kis[f[j]-1]==2&&wis[vis[j]]!=1&&wis[vis[j]-1]!=1)||(kis[f[j]-1]<=1&&wis[vis[j]]==1)) ans++,wis[j]=1;//,wk(i),wh(j);
				kis[f[j]]++;
			}
			for(int j=1;j<=i;j++) wis[j]=0;
		}wh(ans);ans=0;
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
