#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long s,sum;
char c[200010],ans[2000000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			ans[++s]=c[i];
		}
	}
	for(int i=1;i<=s/2;i++)
	{
		if(ans[i]!=ans[s-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
