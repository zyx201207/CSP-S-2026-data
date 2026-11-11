#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ids1,ids2,sum;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ids2=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(ids1<=ids2||a[ids1]!=0)
	{
		if(a[ids1]==0)ids1++;
		if(a[ids2]==0)ids2--;
		if(c[ids1]==c[ids2])
		{
			if(a[ids1]>a[ids2])
			{
				a[ids1]-=a[ids2];
				a[ids2]=0;
			}
			else
			{
				a[ids2]-=a[ids1];
				a[ids1]=0;
			}
		}
		else
		{
			if(a[ids1]>a[ids2])
			{
				sum+=a[ids2];
				a[ids1]-=a[ids2];
				a[ids2]=0;
			}
			else
			{
				sum+=a[ids1];
				a[ids2]-=a[ids1];
				a[ids1]=0;
			}
		}
	}
	cout<<sum;
	return 0;
}

