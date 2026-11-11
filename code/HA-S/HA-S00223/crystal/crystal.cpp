#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (long long)(1e18)

const int N=5e5+10;

int n,m;
int a[N];

inline int read(){
	int t=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?(-1):(f),c=getchar();
	while(c>='0'&&c<='9') t=(t<<3)+(t<<1)+(c^48),c=getchar();
	return t*f;
}

int sum[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r>>1);
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
//		cout<<"i:"<<i<<" l:"<<l<<"\n";
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
//8min

