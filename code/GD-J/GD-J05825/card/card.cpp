#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],sum[500005];
bool ok[500005];
long long p[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int num=0;
		int k=0;
		for(int j=i;j<=n;j++)
		{
			b[k]=a[j];
			k++;
			if(ok[a[j]]=false){
				ok[a[j]]=true;
				p[a[j]]=j;	
			}
			else {
				for(int l=p[a[j]]+1;l<=j;l++)
				{
					b[l]=0;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			cout<<a[j]<<" ";
			sum[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}

