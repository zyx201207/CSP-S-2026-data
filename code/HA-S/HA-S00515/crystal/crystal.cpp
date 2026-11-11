#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=5e5+5,inf=1e12+5;
int n,m,mn=inf,a[N],sum[N];
bool check(int len){
	int l=1,r=len;
	while(r<=n){
		int qu=sum[r]-sum[l-1];
		int k=a[r]*len;
		if(k-qu<=m) return 1;
		l++,r++;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read(),mn=min(mn,a[i]);
	for(int i=1; i<=n; i++) a[i]=a[i]-mn;
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

