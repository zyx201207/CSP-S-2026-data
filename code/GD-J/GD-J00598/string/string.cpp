#include<bits/stdc++.h>
using namespace std;
int hw(string s)
{
	int l=0,r=s.size()-1,ans=0;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long len=0,a;
	long long zh=0;
	char s;
	string b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(int j=1;j<=a;j++)
			b+=s;
	}
	cout<<hw(b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
