#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;int n,a,x;char c;
signed main()
{

	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>> n;
	for (int i=1;i<=n;i++){
		cin>> a >> c;
		while (a--){
			s+=c;
		}
	}
	for (int i=0;i<s.size()/2;i++){
		if (s[i]!=s[s.size()-i-1]) x++;
	}
	cout<< x;

return 0;
}

