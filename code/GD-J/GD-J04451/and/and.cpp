#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,d;
vector<ll> o(2e5+10);
vector<ll> s(2e5+10);	 
ll Max=-1e18;
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>o[i];
		if(i==1)d=o[1];
		else d= d&o[i];
		Max=max(Max,o[i]);
	}
	if(m==n){
		cout<<d;
		return 0;
	}
	for(int i=1;i<=n;i++){
		d=o[i];
		for(int j=i+1;j<=n;j++){
			d=max(d,d &o[j]);
		}
	}
	if(m==1){
		cout<<Max;
		return 0; 
	} 
	if(m==2){
		cout<<d;
		return 0;
	}
	
	return 0;
} 
