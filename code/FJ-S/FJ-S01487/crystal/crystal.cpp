#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

inline int read(){
	int f=1,x=0;
	char gc=getchar();
	while(gc<'0' || gc>'9'){
		if(gc=='-') f=-1;
		gc=getchar();
	}
	while(gc>='0' && gc<='9'){
		x=x*10+(gc-'0');
		gc=getchar();
	}
	return x*f;
}

int n,m,a[N],f[N],ans;

inline bool check(int k){
	int i=0;
	for(int j=k;j<=n;j++){
		i=j-k+1;
		if(a[j]*(j-i)-(f[j-1]-f[i-1])<=m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	int l=1,r=n+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%d",ans);
	return 0;
}
