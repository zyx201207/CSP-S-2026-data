#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],lo;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string p="";
	for(ll i=0;i < n;i++){
		cin >> a[i] >> c[i];
		lo+=a[i];
	}
	string x1="",x2="";
	ll po=lo/2;
	for(ll i=0;i < n;i++){
		for(ll j=0;j < a[i];j++){
			x1+=c[i];
			if(x1.size() == po) break;
		}
		if(x1.size() == po) break;
	}
	for(ll i=n;i > 0;i--){
		for(ll j=0;j < a[i];j++){
			x2+=c[i];
			if(x2.size() == po) break;
		}
		if(x2.size() == po) break;
	}
	if(x1 == x2){
		cout << 0;
		return 0;
	}
	ll cnt=0;
	for(ll i=0;i < po;i++){
		if(x1[i] != x2[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
