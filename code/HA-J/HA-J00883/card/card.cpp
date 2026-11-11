#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
long long n = 0,m = 0,a = 0,q[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	while(n--)
	{
		memset(q,0,sizeof(q));
		int i = 1,sum[N];
		memset(sum,0,sizeof(sum));
		cin>>a;
		q[i] = a;
		for(int j = 1;j <= n;j++)
		{
			if(q[j] == a)
			{
				sum[j]++;
				for(int k = j;k <= n;k++)
				{
					q[j] = 0;
				}
			}
		}
		if(i == n)
		{
			for(int j = 1;j <= n;j++)
			{
				cout<<sum[j];
			}
		}
	}
	return 0;
}
