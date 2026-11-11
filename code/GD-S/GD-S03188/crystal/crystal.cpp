#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0ll,f=1ll;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
bool is;
ll n,m,mx,ans=1;
ll a[500100];
ll check(int x){
	for(int i=1;i<=n-x+1;i++){
		ll sum=0;
		for(int j=i+x-1;j>=i;j--){
			sum+=(a[i+x-1]-a[j]);
		}
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				is=1;
			}
		}
	}
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	for(int i=1;i<=n;i++){
		mx+=a[n]-a[i];
	}
	if(mx<=m){
		cout<<n;
		return 0;
	}else if(!is){
		ll d=a[2]-a[1];
		for(int i=n;i>=1;i--){
			if(m>=i*(i-1)*d/2){
				cout<<i;
				return 0;
			}
		}
	}else{
		int l=1,r=n,mid;
		while(l<=r){
			mid=(l+r)/2;
			ll t=check(mid);
			if(t){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}
