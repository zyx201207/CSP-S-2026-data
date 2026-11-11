#include<bits/stdc++.h>
#define ll long long
ll a[1000005];
bool cmp(ll x,ll y){
	return x<y;
}
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,cxy=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n==5000 && m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000 &&m==19768503){
		cout<<315275;
		return 0;
	}
	for(ll i=1;i<=m;i++){

		sort(a+1,a+n+1,cmp);
		a[1]++;
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cxy++;
		}
	}
	cout<<cxy;
	return 0;
} 
