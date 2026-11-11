#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,ans;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>n;
	for (int i = 1;i <= n;i++){
		ll a;
		char c;
		cin >>a>>c;
		for (int j = 1;j <= a;j++){
			s += c;
		}
		
	}
	ll len = s.size();
	ll j = len-1;
	for (int i = 0;i < len/2;i++){
		if (s[i] != s[j]){
			ans++;
		}
		j--;
	}
	cout <<ans;
	return 0;
}


