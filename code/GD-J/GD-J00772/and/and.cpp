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
const ll N=4e5+5;
ll n,m,a[N],ans;
bool ok[N],ok1[N];
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	For(i,1,n)a[i]=read(),ok[i]=1;
	Rep(w,30,0){
		ll sum1=0;
		For(i,1,n){
			if(ok[i] && (a[i]&(1<<w)))ok1[i]=1,sum1++;
			else ok1[i]=0;
		}
		if(sum1>=m){
			ans+=(1<<w);
			For(i,1,n)ok[i]=ok1[i];
		}
	}
	printf("%lld",ans);
	return 0;
}


