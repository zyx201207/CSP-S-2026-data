#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n = 0,sum = 0,a[N],maxn,cnt = 0;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(c[i] == c[i - 1])
		{
			cnt++;
		}
	}
	if(cnt == n - 1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		sum += maxn * (n / 2);
		cout<<sum;
	}
	return 0;
}
