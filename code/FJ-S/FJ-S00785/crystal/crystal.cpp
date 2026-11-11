#include<bits/stdc++.h>
using namespace std;
bool flag=true;
long long n,ans,cnt;
long long m,a[500005],f[500005];
long long read(){
	long long x=0,t=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-') t=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*t;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read(),flag=(a[i]==i?flag:0);
	if(flag&&n>=500000){
		cout<<min(n,(1ll+(long long)(sqrt(8*m+1)))>>1);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) f[i]=(a[i]-a[i-1])*(i-1)+f[i-1];
	for(int i=2;i<=n;i++){
		long long l=1,r=i-1,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(f[i]-f[mid]>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	return 0;
}
