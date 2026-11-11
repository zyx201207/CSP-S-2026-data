#include<bits/stdc++.h>
using namespace std;
long long n,o=1,l=0,ans=0;
string a[1000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long much;
		string what;
		cin>>much>>what;
		for(int j=o;j<o+much;j++)
		{
			a[j]=what;
		}
		o=o+much;
	}
	
	l=o-1;
	for(int i=1;i<=o;i++)
	{
		if(i%2==1&&i==l)
		{
			cout<<ans;
			return 0;
		}
		if(i%2==0&&i>l)
		{
			cout<<ans;
			return 0;
		}
		if(a[i]!=a[l])
		{
			a[l]=a[i];
			ans++;
		}
		l--;
	}
	
	
	
	
	cout<<ans;
	return 0;
}
