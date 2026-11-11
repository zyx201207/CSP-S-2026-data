#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N=10e6+10;
ll a[N];
string c[N],s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,o=0,sum=0,t=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++){
			s[t]=c[i];
			t++;
		}
	}
	o=t-1;
	for(ll i=0;i<t/2;i++){
		if(s[i]!=s[o])sum++;
		o--;
	}
	cout<<sum;
	return 0;
}
