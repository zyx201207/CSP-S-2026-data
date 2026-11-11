#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a,c;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int l=0;l<a;l++)
		{
			s+=c;
		}
	}
	string ss=s;
	reverse(ss.begin(),ss.end());
	for(int i=0;i<s.size();i++)
	{
		if(ss[i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}