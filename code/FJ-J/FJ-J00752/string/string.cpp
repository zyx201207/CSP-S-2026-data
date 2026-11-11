#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,s,cnt=0;
char c[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++)
		{
			cin>>c[j];
			cnt++;
		}
	}
	long long l=1,r=cnt,num=0;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			l++,r--;
		}
		else if(a[r]>=a[l])
		{
			for(int i=1;i<=a[l];i++)
			{
				c[l]=c[r];
				num++;
			}
			l++,r--;
		}
		else
		{
			for(int i=1;i<=a[r];i++)
			{
				c[r]=c[l];
				num++;
			}
			r++,l--;
		}
	}
	cout<<num;
	return 0;
}
