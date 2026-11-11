#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char ch;
		cin>>ch;
		while(a[i]--)
			s+=ch;
	}
	int ans=0,x=0;
	for(int i=n+1;i>=n/2+1;i--)
	{
		if(s[x]!=s[i])
			ans++;
		x++;
	}
	cout<<ans;
	return 0;
}
