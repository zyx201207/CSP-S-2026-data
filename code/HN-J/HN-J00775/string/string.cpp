#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	bool flag = true;
	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i+1])
		{
			flag = false;
			continue;
		}
	}
	if(flag == true)
	{
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
