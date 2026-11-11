#include<bits/stdc++.h>
using namespace std;
long long a[500005],num[300005][2],f[500005],n,m,ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
		num[a[i]][0]++;
		num[a[i]][1]++;
	}
	for(int i = 1;i <= n;i++)
	{
		f[i]+=num[a[i]][0]-(num[a[i]][1]-num[a[i]][0]);
		num[a[i]][0]--;
		if(num[a[i]][0]==0)
		{
			long long x=num[a[i]][1];
			f[i]-=(x-1)*x/2;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		f[i]=f[i-1]+f[i];
		ans[a[i]]=max(ans[a[i]],i-f[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		ans[i]=max(num[i][1],ans[i]);
		cout <<ans[i]<<' ';
	}
	return 0;
}
