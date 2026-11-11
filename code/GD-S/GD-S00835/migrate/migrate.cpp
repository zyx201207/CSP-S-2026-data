#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=105;
ll C,_,n,d,a[N],sum[N][N],mi[N][N],idx[N];
il void solve(){
	n=read(),d=read();
	For(i,1,n)a[i]=read();
	if(C<=25){
		For(i,1,n)For(j,1,n)sum[i][j]=0,mi[i][j]=0;
		For(i,1,n){
			For(j,i+1,n){
				ll now=i;
				while(mi[i][j]<=n && now<j)now=upper_bound(a+1,a+1+n,a[now]+d)-a-1,++mi[i][j];
			}
		}
		for(ll i=1;i<(1<<n);++i){
			vector<ll> f;
			For(j,0,n-1)if(i&(1<<j))f.pb(j+1);
			if(f.size()<2)continue;
			bool ok=1;
			for(ll i=1;i<(ll)f.size();++i){
				if(a[f[i]]-a[f[i-1]]>d){
					ok=0;
					break;
				}
			}
			if(ok && f.size()-1==mi[f[0]][f.back()]){
				sum[f[0]][f.back()]++;
			}
		}
		ll res=0;
		For(i,1,n)For(j,i+1,n)res+=(sum[i][j]==2);
		printf("%lld\n",res);
	}
	if(C>=11 && C<=12){
		
		return;
	}
	if(C>=13 && C<=14){
		
		return;
	}
	if(C>=15 && C<=18){
		
		return;
	} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),_=read();while(_--)solve();
	return 0;
}

