#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,cnt=1,x=1,s=1,mmax=0;
int a[500005];
int dp[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int p=0;
	bool aaa=0;
	bool xxx=0;
	bool sss=0;
	for(int j=1;j<=n;j++)
	{
		cnt=1;
		aaa=0;
		x=1;
		s=1;
		xxx=0;
		sss=0;
		for(int i=1;i<=m;i++)
		{
			if(aaa==0)
			{
				if(j-x>0)
				{
					p=a[j-x];
					aaa=1;
				}
				else
				{
					break;
				}
			}
			if(p==a[j]&&xxx==0)
			{
				cnt++;
				aaa=0;
				x+=1;
				i--;
				continue;
			}
			p++;
			xxx=1;
			if(p==a[j])
			{
				cnt++;
				aaa=0;
				x+=1;
			}
		}
		mmax=max(mmax,cnt);
	}
	cout<<mmax;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
