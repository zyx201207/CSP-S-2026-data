#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;//ACACACACACACACACACACACACACACAC
		for(int j=1;j<=a;j++){
			s.push_back(c);
		}
	}
	ll mid=s.size()/2;
	ll c1=0,c2=0;
	for(int i=0;i<mid;i++){
		if(s[i]!=s[s.size()-i-1]) c1++;
	}
	ll l=s.size();
	for(int i=mid;i<l;i++){
		if(s[i]!=s[s.size()-i-1]) c2++;
	}
	cout<<max(c1,c2);
	return 0;
}
