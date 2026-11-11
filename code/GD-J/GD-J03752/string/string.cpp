#include <bits/stdc++.h>
using namespace std;
const int m=1e6;
char s[m];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	int n;
	long long a;
	cin>>n;
	if(n==1)
	{
		cin>>a>>c;
		cout<<"0";
		return 0;
	}
	int h=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		cout<<a<<c<<endl;
		for(int j=0;j<a;j++)
		{
			h++;
			s[h]=c;
		}
	}
	long long ans=0;
	for(int i=1;i<=h/2;i++)
	{
		if(s[i]!=s[h-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
