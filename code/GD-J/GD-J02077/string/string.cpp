#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,s,ans;
char c;
string S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s>>c;
		for(ll j=1;j<=s;j++){
			S+=c;
		}
	}
	for(ll i=0;i<S.size()/2;i++){
		if(S[i]!=S[S.size()+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
