#include<bits/stdc++.h> 
using namespace std;
int a[200000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	int big=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		long long cnt=0;
		long long dm=m;
		for(int j=i;j>0;j--)
		{
			if(a[j]==a[i])
			{
				cnt++;
			}
			else if(dm >= a[i] - a[j])
			{
				dm -= a[i] - a[j];
				cnt++;
			}
			else
			{
				break;
			}
			if(big < cnt)
			{
				big = cnt;
			}
		}
	}
	cout << big;
	return 0;
}
