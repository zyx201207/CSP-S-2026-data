#include<bits/stdc++.h>
#define ll long long
using namespace std;

int calculate(){
	ll n,d;
	cin>>n>>d;
	
	ll kuadu=2*d-1;
	ll feifu=0;
	
	ll array[n]={};
	for(ll i=0;i<n;i++){
		cin>>array[i];
	}
	
	if(array[0]<=0){
		feifu=1-array[0];
	}
	
	ll ans=array[n-1]+feifu-kuadu;
	
	return ans;
	
} 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	
	while(t--){
		cout<<calculate()<<"\n";
	}
	return 0;
}
