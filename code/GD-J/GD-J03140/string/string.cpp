#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(ll i=1;i<=n;i++){
	ll a;
	char b;
	cin>>a>>b;
	for(ll j=1;j<=a;j++){
		k+=b;
	}
}
//for(ll i=0;i<k.size();i++){
//	cout<<k[i];
//}
ll siz=k.size();

	for(ll i=0;i<siz/2;i++){
//		cout<<k[i]<<" "<<k[siz-1-i]<<endl;
		if(k[i]!=k[siz-1-i]){
			ans++;
		}
	}


cout<<ans;
	return 0;
}
