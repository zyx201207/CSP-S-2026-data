#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,r=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>x;
	while (x--){
		ll n;
		char a;
		cin>>n;
		cin>>a;
		for (int i=1;i<=n;i++) s+=a;
	}
	for (int i=0;i<=s.size()-1;i++){
		if (s[i]!=s[s.size()-i-1]) r++;
	}
	cout<<r/2;
	return 0;
}
