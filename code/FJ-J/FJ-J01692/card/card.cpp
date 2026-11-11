#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5*100000+10],cnt[3*100000+10]; 
vector<ll>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll j=1;j<=m;j++){
		cout<<n-j+1;
	}
	/*for(ll i=1;i<=n-1;i++){
		for(ll j=i;j<=n;j++){
			if(v.find(a[j])){
				ll pos=v.find(a[j]-'0');
				v.erase(v.begin()+pos,v.size()-pos);
				v.push_back(a[j]);
				
			}
			else {
				v.push_back(a[j]);
			}
		}
		for(ll j=1;j<=m;j++){
			if(v.find(j))cnt[j]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[j]<<' ';
	}*/
	return 0;
}
