#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=a[1],st=1,en=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]*(en-st+1)-sum<=m)
		{
			sum+=a[i];
			en++;
			maxn=max(maxn,en-st+1);
		} 
		else
		{
			for(int j=st;j<=en;j++)
			{
				sum-=a[j];
				st++;
				if(a[i]*(en-st+1)-sum<=m)
				{
					sum+=a[i];
					en++;
					maxn=max(maxn,en-st+1);
					break;
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
