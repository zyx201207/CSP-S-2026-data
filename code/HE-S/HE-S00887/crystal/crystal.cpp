#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]<m)
		{
			ans++;
			m-=(a[i]-a[i-1]);
		}
		else
		{
			cout << ans;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
