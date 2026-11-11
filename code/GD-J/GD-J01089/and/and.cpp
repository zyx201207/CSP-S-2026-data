#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,m,a[N],ans;
bool sv(ll x){
	ll b=1;
	for(int i=2;i<=30;i++){
		b*=2;if(x==b)return 0;
	}return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<ll>());
	ll m2=m;
	if(m==1)cout<<ans;
	//cout<<sv(512)<<' '; 
	for(int i=1;i<=m;i++){
		if(sv(a[i])==0){m++;continue;}
		if(i==m-m2+1){ans=a[i];}
		else {ans&=a[i];}
	}cout<<ans;
	return 0; 
}
