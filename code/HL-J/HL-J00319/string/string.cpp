#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,cnt=0;
	cin>>n;
	string s,b;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>s;
		for(ll j=1;j<=a[i];j++){
			b+=s;
		}
	}
	ll a=b.size()-1;
	for(ll i=0;i<b.size()/2;i++){
		if(a!=-1){
			if(b[i]!=b[a]){
				cnt++;
				a--;
			}
		}
	}
	cout<<cnt;
	return 0;
}