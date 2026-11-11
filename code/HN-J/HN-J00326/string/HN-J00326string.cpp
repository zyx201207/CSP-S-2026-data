#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	long long n,m=-1,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		m+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=m/2+1;i<=m;i++)
	{
		if(s[i]!=s[m-i]) ans++;
    }
	cout<<ans;
	return 0;
}
