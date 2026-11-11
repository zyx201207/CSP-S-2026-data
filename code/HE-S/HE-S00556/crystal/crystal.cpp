#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	if(x%2==0)return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long a[n+1];
	long long sum=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int z;
	if(check(n))z=a[n/2];
	else z=a[n/2+1];
	while(m)
	{
		for(int i=2;i<=z;i++)
		{
			if(a[i]<z&&m-1>=0)
			{
				a[i]++;
				m--;
			}
			else
			{
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])sum++;
	}
	cout<<sum;
	return 0;
}
