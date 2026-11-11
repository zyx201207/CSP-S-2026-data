#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,a[N];
char c[N];
string s;
ll sum;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string b=s;
	reverse(s.begin(),s.end());
	if(b==s) {cout<<0;return ;}
	ll q=s.size();
	for(int i=1;i<=q;i++){
		if(b[i]!=s[i]){
			sum++;
			b[i]=s[i];
			s[q-i-1]=s[i];
		}
	}
	cout<<sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
