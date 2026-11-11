#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long mo[50][3],bit=1;
long long maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=40;i++)
	{
//		mo[i][0]=bit;
//		bit*=2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long sum=a[i],j=0;
		while(sum!=0)
		{
			mo[j][1]+=sum%2;
			sum=sum/2;
			j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long num=a[i],l=0,minn=1e9;
		while(num!=0)
		{
			if(num%2==1)
			{
				minn=min(minn,mo[l][1]);
			}
			num=num/2;
			l++;
		}
		if(a[i]==0) minn=0;
		if(minn>=m)
		{
			maxn=max(maxn,a[i]);
		}
	}
	cout<<maxn;
	return 0;
}
