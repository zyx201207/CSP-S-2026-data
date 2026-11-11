//GZ-S00102 遵义市第五中学 罗子懿
#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6+10;
long long n,m,cry[MAXN],dp[MAXN],c[MAXN];
void init()
{
	for(int i = 1;i<=n;i++)
	{
		c[i] = cry[i]-cry[i-1];
	}
	return;
}
void print()
{
	long long maxn = INT_MIN;
	for(int i = 1;i<=n;i++)
	{
		maxn = max(maxn,dp[i]);
	}	
	cout<<maxn;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
		cin>>cry[i];
    }
    sort(cry+1,cry+1+n);
    init();
	for(int i = 1;i<=n;i++)
	{
		if(i==1)
		{
			dp[i] = 1;
			continue;
		}
		int sta = 0,cnt = 1,point = i,add = c[i];
		while(1)
		{
			if(point == 0 || point == 1) break;
			if(c[i] == 0)
			{
				dp[i] = dp[i-1]+1;
				break;
			}
			sta+=add;
			if(sta>m)
			{
				dp[i] = cnt;
				break;
			}else
			{
				cnt++;
				dp[i] = cnt;
				point--;
				add+=c[point];
			}
		}
	}
	print();
    return 0;
}
