#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5e5;
int a[N],num[N],b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[i]=0;	
	}
	for(int o=0;o<n;o++){
		for(int i=1+o;i<=n;i++)
		{
			b[i]=a[i];
			for(int j=i;j>1;j--)
			{
				if(b[i]==b[j-1])
					for(int k=j-1;k<i;k++)
						b[k]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1+o;j<=n;j++)
			{
				if(b[j]==i)	num[i]++;
			}
		}
		for(int i=1;i<=n;i++)
		b[i]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<" ";
}
