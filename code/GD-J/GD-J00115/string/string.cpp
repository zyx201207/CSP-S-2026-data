#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string sum;
	long long ans;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++)
		{
			sum+=c[i];
		}
	}
	long long j=sum.size()-1; 
	for (int i=0;i<sum.size()/2;i++)
	{
		if (sum[i]!=sum[j])
		{
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}
