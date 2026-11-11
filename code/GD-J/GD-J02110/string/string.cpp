#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s=" ";
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int x;char c;
		cin>>x>>c;
		string s1(x,c);
		s+=s1;
	}
	for(int i=1,j=s.size()-1;i!=j;++i,--j)
	{
		if(s[i]!=s[j]) ++ans;
	}
	cout<<ans;
	return 0;
}
