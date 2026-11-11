#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long ans = 0;
	for(int i = 1;i<=n/2;i++)
	{
		if(c[i]!=c[n-i+1])
		{
			if(c[i]!=c[n-i])
			{
				ans+=max(a[i],a[n-i+1]);
				a[n-i] -= max(a[i],a[n-i+1])-min(a[i],a[n-i+1]);
			}
			else
			{
				ans+=min(a[i],a[n-i+1]);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
