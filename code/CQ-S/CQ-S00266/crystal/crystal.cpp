#include<bits/stdc++.h>
const int QWQ=5e5+5;
using namespace std;
using LL=long long;
template<typename T=LL>
inline T read(){
	T x=0; int f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int n,ans; LL m,a[QWQ],sa[QWQ];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read<int>(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	for (int i=1;i<=n;i++){
		int l=1,r=i,j=i;
		for (;l<=r;){
			int mid=(l+r>>1);
			if (a[i]*(i-mid+1)>sa[i]-sa[mid-1]+m) l=mid+1;
			else r=mid-1,j=mid;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
