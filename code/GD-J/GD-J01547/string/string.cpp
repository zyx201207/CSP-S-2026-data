#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
int mj;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>mj;
	for(int i=1;i<=mj;i++){
		ll x;
		char q;
		cin>>x>>q;
		for(int j=1;j<=x;j++){
			s+=q;
		}
	}
	ll L=s.size()-1,ans=0;
	for(int i=0;i<=(L-1)/2;i++){
		if(s[i]==s[L-i]){
			continue;
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
