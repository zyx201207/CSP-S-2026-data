#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
ll n,a[N],s,k;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],s+=a[i];
	ll l=1,r=n,ls=a[1],rs=s-a[n],lp=0,rp=s;
	while(1){
		if(l==r)break;
		if(b[l]!=b[r])k+=min(ls-lp,rp-rs);
		if(ls>s-rs)lp=s-rs,rp=s-lp,r--,rs-=a[r];
		else rp=s-ls,lp-s-rp,l++,ls+=a[l];
	}
	cout<<k;
	return 0;
}
