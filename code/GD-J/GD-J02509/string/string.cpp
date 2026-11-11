#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	ll ttl = 0;
	string s;
	for (int i = 0;i < n;i++)
	{
		char ci;
		cin >> a[i] >> ci;
		for(int j = 0;j < a[i];j++)
		{
			s+=ci;
		}
		ttl+=a[i];
	}
	ll hfl = ttl/2,ans = 0;
	string s1 = s.substr(0,hfl),s2 = s.substr(hfl+ttl%2);
	for (int i =0;i < hfl;i++)
	{
		ans+=(s1[i]!=s2[i]);
	}
	cout << ans;
	return 0;
}
//
