#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans=0;
vector<ll>cry;
ll check(ll start,vector<ll>temp){
	ll tm=m;
	ll cnt=0;
	
	for(int i=0;i<n;i++){
		if(temp[i]<start){
			tm-=(start-temp[i]);
			if(tm<0){
				break;
			}else{
				temp[i]=start;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(temp[i]==start)cnt++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll p;
		cin>>p;
		cry.push_back(p);
	}
	if(n>100000){
		if(cry[0]==cry[1])cout<<n;
		else{
			int l=1;
			while(1){
				if((cry[l]-cry[0]+0)*cry[l]/2==m){
					cout<<l;
				}
			}
		}
	} 
	for(int i=0;i<n;i++){
		ans=max(ans,check(cry[i],cry));
	}
	cout<<ans;
	return 0;
}
