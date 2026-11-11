#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin,(x).end
#define fi first
#define se second
#define pb push_back
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll now=0;
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		for(ll j=now;j<=now+x-1;j++){
			a+=c;
		}
		now+=x;
	}
	int mid;
	int k=a.size();
	if(k%2==1){
	    mid=(a.size())/2;
	}
	else{
	    mid=(a.size())/2-1;
	}
	
	for(ll i=0;i<=mid;i++){
		if(a[i]!=a[k-1-i]){ 
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}



































































































































































































