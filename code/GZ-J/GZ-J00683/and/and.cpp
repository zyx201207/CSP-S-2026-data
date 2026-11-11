//GZ-J00683 遵义市第十二中学 兰至立 
#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005]={0},b[200005][40]={0},sum=1,k=0,c[200005]={0},num=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
	for(long long j=1;j<=30;j++)
	{
		sum*=2;
		if(sum>a[i])
		{
			b[i][j-1]=1;
			a[i]-=sum;
			k=j-1;
			break;
	}
	
	for(long long j=k;j>=1;j--)
	{
		sum/=2;
		if(a[i]>=sum)
		{
			a[i]-=sum;
			b[i][j]=1;
		}
	}
	}
}
for(int i=30;i>=1;i--)
	{
		for(int j=1;j<m;j++)
		{
			for(int l=j+1;l<=m;l++)
			{
				if(b[j][i]==b[l][j])
				{
					num+=pow(2,n);
				}
			}
		}
	}
	cout<<num;
	return 0;
}
