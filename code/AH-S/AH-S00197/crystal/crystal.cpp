#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
template<typename TP>
inline TP read(){
	TP f=1,x=0;char ch=gc();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=gc();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}
	return f*x;
}
const int N=5e5+105;
typedef long long ll;
int n,num;
ll m,b[N],a[N],ans,cnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	n=read<int>();m=read<ll>();
	for(int i=1;i<=n;i++){
		a[i]=read<ll>();
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	num=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+1+num,a[i])-b;
		++cnt[p];
	}

	for(int i=1;i<=num;i++) ans=max(ans,cnt[i]);
	ll tol=cnt[1],s=0,l=1,lt=cnt[1];
	for(int x=2;x<=num;x++){
		s+=tol*(b[x]-b[x-1]);
		tol+=cnt[x];
		if(s<=m){
			ans=max(ans,tol);
		}
		else{
			while(s>m){
				s-=lt*(b[x]-b[l]);
				tol-=lt;
				lt=cnt[++l];
			}
			ll ts=m-s;
			ll tt=min(ts/(b[x]-b[l-1]),cnt[l-1]);
			if(tt){
				s+=tt*(b[x]-b[l-1]);tol+=tt;lt=tt;--l;
			}
			ans=max(ans,tol);
		}
	}
	printf("%lld\n",ans);
}
