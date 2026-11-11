#include<bits/stdc++.h>
using namespace std;
int q[500005];
int n,m,a[500005],t[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(m==2)
	{
		int sum=0,sum2=0;
		if(a[n]==1)
		{
			sum=n;
			for(int i=1;i<=n;i++)
				if(a[i]==2) sum2++;
		}
		else
		{
			sum2=n;
			for(int i=1;i<=n;i++)
				if(a[i]==1) sum++;
		}
		cout<<sum<<" "<<sum2;
		return 0;
	}
	if(flag==1)
	{
		for(int i=1;i<=n;i++)
			t[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<t[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int d=0;
		for(int j=i;j<=n;j++)
		{
			int f=d;
			for(int k=1;k<=f;k++) 
			{
				if(q[k]==a[j])
				{
					for(int l=k;l<=f;l++) d--;
					break;
				}
			}
			d++;
			q[d]=a[j];
		}
		for(int j=1;j<=d;j++) t[q[j]]++;
		memset(q,0,sizeof q);
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
