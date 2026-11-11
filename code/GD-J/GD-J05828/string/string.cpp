#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	char a[250000];
	int c[250000];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		s+=a[i]*c[i];
		cnt+=a[i];
	}
	if(cnt%2==0)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(s[i]!=s[cnt-i+1])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i=1;i<n/2;i++)
		{
			if(s[i]!=s[cnt-i+1])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
