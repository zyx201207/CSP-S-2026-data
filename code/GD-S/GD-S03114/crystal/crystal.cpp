#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[500005];
int sum[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 
	cin>>n>>m;//共有n个数，m次操作 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	sum[1] = 0;
	for(int i=2;i<=n;i++)
	{
		sum[i] = a[i]-a[i-1];
	}
	
	long long cnt = 1,num = a[1];//cnt当前有多少个水晶是相同的，num当前相同的水晶的值为多少 

	while(cnt<n)
	{
		int bi = cnt+1;
		if(m>=cnt*sum[bi])
		{
			m-=(cnt*sum[bi]);
			num +=sum[bi];
			cnt++;
		}
		else 
		{
			
			cout<<cnt;
			return 0;	
		}
	}
	cout<<cnt;
	return 0;
}
