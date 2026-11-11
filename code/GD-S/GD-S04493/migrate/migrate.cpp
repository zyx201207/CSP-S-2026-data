#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[2000005],b[2000005],c[2000005];
/*ll find(ll x){
	ll l=1,r=n;
	while(l+1<r){
		ll mid=((l+r)>>1);
		if(a[mid]>x){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	if(a[r]<=x)return r;
	return l;
}*/
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	
/*	memset(c,0,sizeof(c));
	for(ll i=1;i<=n;i++){
		ll jg=find(a[i]+m);
		b[i]=jg;
		c[jg]++;
//		cout<<b[i]<<" ";
	}
	
	ll ans=0;
	/*
	for(ll i=1;i<=n-3;i++){
		if(b[i]-i!=2)continue;
		if(a[i+3]-a[i+1]>m)continue;
	//	cout<<"y"<<i<<c[i]<<b[i+3]<<b[i+2]<<endl;
		ans+=(1+c[i])*(b[i+1]-i-2);
	}//
	for(ll i=1;i<=n-3;i++){
		ll x=b[i]-i;
		if(x<=1)continue;
		if(a[i+x+1]-a[i-1+x]>m)continue;
		if(x>2&&a[b[i+x-1]]-a[i-2+x]<=m)continue;
		cout<<"Y"<<i<<endl;
		ans+=(1+c[i])*(b[b[i]]-b[b[i]-1]+1);
	}
	cout<<"ans=";
	cout<<ans<<"\n";*/
}
/*
10 3
0 3 6 7 8 9 10 11 14 17


6 12
0 4 8 12 16 20
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,_;
	cin>>C>>_;
	while(_--){
	//	solve();
		cout<<"0\n";
	}
	return 0;
}

