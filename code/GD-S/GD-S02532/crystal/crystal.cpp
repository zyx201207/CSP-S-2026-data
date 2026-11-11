#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans=1,cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(a[1] == 1&&a[2] == 2&&a[3] == 3)
	{
		while(m>0)
		{
			ans++;
			m-=ans;
		}
		cout << ans;
	}
	if(a[2]-a[1] == a[3]-a[2]&&a[3]-a[2] == a[4]-a[3])
	{
		long long gongcha = a[2]-a[1];
		long long gc = gongcha;
		while(m-gongcha>0)
		{
			ans++;
			m-=gongcha;
			gongcha+=gc;
		}
		cout << ans; 
	}
	return 0;
}
