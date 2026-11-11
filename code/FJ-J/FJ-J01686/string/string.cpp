#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,sum;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		sum+=a[i];
	}
	for(int i=0;i<sum;i++)
	{
		if(s[i]!=s[sum-1-i])
			ans++;	
	}
	cout<<ans/2;


	return 0;
}

