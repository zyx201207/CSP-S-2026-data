#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a;
	string b;
	for(int i=1;i<=n;i++) {
		cin>>a>>b;
		for(int j=1;j<=a;j++) s+=b;
	}
	int ans=0;
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(s[i] != s[s.size()-i-1]) ans++;
	}
	cout <<ans;
	return 0;
}
