#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin >> n;
	while(n--)
	{
		long long a;
		char c;
		cin >> a >> c;
		while(a--)
			s+=c;
	}
	//cout << s <<"\n";
	string s1=s;
	reverse(s.begin(),s.end());
	//cout << s <<'\n';
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
			ans++;
	}
	cout << ans/2;
	return 0;
}
