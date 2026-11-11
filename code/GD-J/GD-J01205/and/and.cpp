#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using ll=long long;
ll a[N];
int main(){
	/*
	4 2
	3 15 12 12
	*/
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	//±©Á¦dp
	ll mx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	ll ans=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll c=a[i]&a[j];
			ans=max(ans,c);
		}
	}
	if(m==2){
		cout<<ans;
	}
	if(m==1){
		cout<<mx;
	}
}
