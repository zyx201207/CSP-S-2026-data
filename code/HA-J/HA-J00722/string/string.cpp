#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,i,a[100010],ans=0,l;
string c[100010],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			ans++;
		} 
		else
		{
			continue;
		}
	}
	cout<<ans;
	return 0;
} 
