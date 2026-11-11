#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int I=5e5+5;
ll a,b,z;
ll n[I],m[I];
ll qz[I];
ll pd(ll r,ll l,ll x){
	if(r==l) return r;
	int mid=(r+l)/2;
	if(qz[x]-qz[mid]>b) return pd(mid+1,l,x);
	else return pd(r,mid,x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>n[i];
	}
	sort(n+1,n+1+a);
	ll p=0;
//	for(int i=1;i<=a;i++){
//		if(n[i]==n[i-1]) cout<<1;
//		else {
//			n[i]=1;
//			p=0;
//			for(int j=p;j>=1;j--) m[i-j]=p+1;
//		}cout<<p<<"\n";
//	}
//	for(int i=1;i<=a;i++) cout<<m[i]<<"\n";
	qz[1]=0;
	for(int i=2;i<=a;i++){
		qz[i]=(i-1)*(n[i]-n[i-1])+qz[i-1];
	}
	for(ll i=1;i<=a;i++){
		int t=pd(1,i,i);
		z=max(z,i-t+m[t]+1);
	}
	cout<<z;
	return 0;
}
