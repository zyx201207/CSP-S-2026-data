#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdin);
	int n;
	cin>>n;
	int a[n+10];
	string c,s;
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
	}
    int p=0;
	int q=s.size()-1;
	int ans=0;
	while(p<q)
	{
		if(s[p]!=s[q])
		{
			ans++;
		}
		p++;
		q--;
	}
	cout<<ans;
	return 0;
}
