#include <bits/stdc++.h>
using namespace std;
unsigned long long n,ans=0,num=0;
long long a[200010];
char c[200010];
string tep;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			tep += c[i];
			num++;
		}
	}
	unsigned long long x=num/2;
	for(int i=0;i<x;i++)
	{
		if(tep[i]!=tep[num-i-1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
