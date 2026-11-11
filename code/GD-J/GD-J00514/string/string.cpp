#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,a;
char c;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	ll sum=0;
	for(ll i=0; i<s.size(); i++) {
		if(s[i]==s[s.size()-i])continue;
		else sum++;
	}
	cout<<sum;
}
