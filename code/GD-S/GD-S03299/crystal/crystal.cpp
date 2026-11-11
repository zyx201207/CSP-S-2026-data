#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],c[500005];
int n,m,ans=-1;
inline int read(){
	int _=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		_=_*10+ch-'0';
		ch=getchar();
	}
	return _*f;
} 
inline int solve(int i){
	int yu=m,x=i;
	if(x==1){
		return i;
	}else{
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)/2;
			if((i-mid+1)*a[i]-(c[i]-c[mid-1])>yu) l=mid+1;
			else if((i-mid+1)*a[i]-(c[i]-c[mid-1])<yu) r=mid;
			else{
				return i-mid+1;
			}
		}
		return i-l+1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	c[0]=0;
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,solve(i));
	}
	cout<<ans;
	return 0;
}
