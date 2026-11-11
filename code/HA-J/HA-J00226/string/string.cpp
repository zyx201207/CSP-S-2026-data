#include<bits/stdc++.h>
#define ll long long
const int N=2e5+100;
using namespace std;
ll n,a[N],ans,r;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ll t=a[i];
		while(t--){
			s+=c[i];
		}
		r+=a[i];
	}
	ll l=1;
	while(l<=r){
		if(s[l]!=s[r])
			ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}