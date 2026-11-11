#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
ll m,a[N],b[N];
int res=1;
int main(){
//	freopen("crystal3.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=(i-1)*(a[i]-a[i-1]);
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(b[mid]-b[i]-1ll*(a[mid]-a[i])*(i-1)<=m){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		res=max(res,ans-i+1);
	}
	//b[j]-b[i]-(i-1)*(a[j]-a[i])
	printf("%d",res);
	return 0;
}
