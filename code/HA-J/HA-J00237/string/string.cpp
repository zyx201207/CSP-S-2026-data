#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long sum;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		sum+=a[i];
		for (int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int flag=1;
	for (int i=1;i<=sum;i++)
	{
		if (s[i]!=s[i+1])
		{
			flag=0;
			break;
		}
	}
	if (flag==1)
	{
		cout << 0;
		return 0;
	}
	int x=0;
	if (sum%2==0) x=sum/2;
	else x=(sum-1)/2;
	long long ans=0;
	for (int i=0;i<=x;i++)
	{
		if (s[i]!=s[sum-1]) ans++;
		sum--;
	}
	cout << ans;
	return 0;
}

