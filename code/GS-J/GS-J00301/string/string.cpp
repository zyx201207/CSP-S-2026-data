#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
ll ans,T,p;
string s,x;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>p;
		char c;cin>>c;
		fo(i,1,p){
			s+=c;
		}
	}
	for(ll i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
