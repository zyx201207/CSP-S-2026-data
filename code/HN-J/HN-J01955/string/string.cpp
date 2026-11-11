#include <iostream>
#include <string>
#define ll long long
using namespace std;
const ll N=1e8;
ll n,a[N],ans;
char c[N];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	ll x=0;
	for(ll i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			b+=c[i];
			x++;
		}
	}
	for(ll i=0;i*2<x;i++){
		if(b[i]!=b[x-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
