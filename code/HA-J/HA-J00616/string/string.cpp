#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int x;
		string a;
		cin>>x;
		cin>>a;
		for(int j=1;j<=x;j++)
			s+=a;
	}
	int l=s.length();
	int L=l;
	l/=2;
	for(int i=0;i<l;i++)
	{
		if(!(s[i]==s[L-1-i]))
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
