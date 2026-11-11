#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=5e5+50;
int n,m,a[N],s[N],ans;
inline void solve(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]*i-s[i]<=m){
			ans=max(ans,i);continue;
		}
		int l=1,r=i+1,mid;
		while(l+1!=r){
			mid=(l+r)>>1ll;
			int Z=(i-mid+1)*a[i];
			if(Z-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	return;
}
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int ttt=1;
	while(ttt--)solve();
	
	return 0;
}
