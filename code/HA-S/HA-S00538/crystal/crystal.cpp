#include<bits/stdc++.h> 
using namespace std;
const int A=5e5+5;
typedef long long ll;
ll a[A],s[A];
int n,m;
ll jugde(int x){
	x--;
	ll rt=1e18;
	for(int i=1;i+x<=n;i++){
		int e=(s[i+x]-s[i-1])/(x+1);
		rt=min(rt,a[i+x]*(x+1)-(s[i+x]-s[i-1]));
	}return rt;
}
int midfd(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		ll z=jugde(mid);
		if(z<=m)l=mid;
		else r=mid-1;
		if(r-l==1)return jugde(r)<=m ? r : l;
		//cout<<z<<":"<<l<<":"<<r<<'\n';
	}return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" ";
		s[i]=s[i-1]+a[i];
	}
	cout<<midfd(1,n);
}
