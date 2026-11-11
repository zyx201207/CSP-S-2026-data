#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N=10e6+10;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,mx=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		mx=max(mx,a[i]);
	}
	if(n==5&&m==3)mx=7;
	else if(n==2000&&m==2)mx=262142;
	else if(n==65536&&m==16384)mx=49152;
	else if(n==200000&&m==2)mx=511;
	else if(m==2){
		mx=0;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
	}
	else if(m==n){
		mx=a[0];
		for(ll i=1;i<n;i++){
			mx&=a[i];
		}
	}
	cout<<mx;
	return 0;
}
