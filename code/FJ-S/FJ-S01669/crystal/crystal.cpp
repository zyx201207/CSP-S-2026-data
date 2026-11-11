#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read(),a[500010],num[500010]={0};
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
	}
	ll l=1,r=n,mid;
	bool b=0;
	while(r!=l+1){
		b=0;
//		cout<<l<<" "<<r<<"\n";
		mid=(l+r)/2;
		for(int i=mid;i<=n;i++){
			if(a[i]*mid-num[i]+num[i-mid]<=m){
				b=1;
				break;
			}
		}
		if(b==1) l=mid;
		else r=mid;
	}
	b=0;
	for(int i=r;i<=n;i++){
		if(a[i]*r-num[i]+num[i-r]<=m){
			b=1;
			break;
		}
	}
	if(b==1) cout<<r;
	else cout<<l;
	return 0;
}

