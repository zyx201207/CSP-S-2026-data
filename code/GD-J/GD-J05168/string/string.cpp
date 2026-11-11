#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string S;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<int> a(n);
	vector<char> s(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[n]>>s[n];
		for(int i=0;i<a[n];i++) S+=s[n];
	}
	for(long long i=0;i<S.size()/2;i++)
	{
		if(S[i]!=S[S.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
