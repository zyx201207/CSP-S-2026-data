#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
typedef long long ll;
const int N=6e5+5;

inline ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,m,a[N],now;

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	
	int cnt=0,ans=0,l=1;
	for(int i=1;i<=n;i++) {
		if(i==1) {
			ans=max(ans,1ll);
			cnt++;
			continue;
		}
		if(a[i]==a[i-1]) {
			cnt++;
			ans=max(ans,i-l+1);
			continue; 
		}
		now+=cnt*(a[i]-a[i-1]);
		while(now>m && l<=i) {
			now-=(a[i]-a[l]);
			cnt--;
			l++;
		}
		cnt++;
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
// Oct31==Dec25?
