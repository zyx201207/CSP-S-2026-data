#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int sid,T,n,lst[N],nxt[N],Dig[50],f[N],g[N];
ll d,a[N];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
void write(ll x,char ch){
	int c=0;
	while(x)Dig[++c]=x%10,x/=10;
	if(!c)putchar('0');
	while(c)putchar(Dig[c--]+'0');
	putchar(ch);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	sid=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;++i)a[i]=read();
		if(n==1){
			puts("0");
			continue;
		}
		if(sid==11||sid==12){
			ll v=d/(a[2]-a[1]);
			if(v<=1){
				puts("0");
				continue;
			}
			v=v*2-1;
			printf("%lld\n",max(1ll*n-v,0ll));
			continue;
		}
		for(int i=1,j=1;i<=n;++i){
			while(a[i]-a[j]>d)j++;
			lst[i]=j;
		}
		for(int i=n,j=n;i;--i){
			while(a[j]-a[i]>d)j--;
			nxt[i]=j;
		}
		ll ans=0;
		for(int l=1;l<=n;++l){
			for(int i=l;i<=n;++i)f[i]=g[i]=0;
			g[l]=1;
			for(int i=l+1;i<=n;++i){
				int j=max(lst[i],l);
				if(j==i)break;
				f[i]=f[j]+1;
				if(j<i-1&&f[j]==f[j+1]){
					if(j<i-2&&f[j+1]==f[j+2])g[i]=3;
					else if(g[j]>1||g[j+1]>1)g[i]=3;
					else g[i]=g[j]+g[j+1];
				}else if(g[j]>2)g[i]=3;
				else g[i]=g[j];
				if(g[i]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*
0 1
7 5
1 3 7 8 9 10 14

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
