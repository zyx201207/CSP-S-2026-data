#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ifstream in("crystal.in");
	ofstream out("crystal.out");
	ll n,m; in>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) {
		in>>a[i];
	}
	sort(a.begin()+1,a.end());
	ll base,mans=0;//=n%2==0?a[n/2]:a[n/2+1];
	for(ll e=1;e<n;e++)
	{
	base=a[e];
	ll ans=1,nm=m;
	for(ll i=e-1;i>0;i--){
		nm-=base-a[i];
		if(nm>=0) ans++;
		else break;
	}
	for(ll i=e+1;i<=n;i++){
		if(a[i]==base) ans++;
		else break;
	}
	if(mans<ans) mans=ans;
	//else break;
	}
	out<<mans;
	return 0;
}
