#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	string s;
	s+=' ';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	ll ans=0;
	for(int i=1;i<(sum+1)/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
