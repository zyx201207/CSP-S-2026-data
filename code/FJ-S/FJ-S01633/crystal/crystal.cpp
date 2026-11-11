#include<bits/stdc++.h>
using namespace std;
#define int ll
#define N 500005
typedef long long ll;
inline int read(){
	register int x=0,f=1ll;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3ll)+(x<<1ll)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
int ans;
int a[N],sum[N];
inline bool check(int i,int mid){
	return (i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,anss=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if (check(i,mid))r=mid-1,anss=mid;
			else l=mid+1;
		}
		ans=max(ans,i-anss+1);
	}
	cout<<ans<<'\n';
	return 0;
}
