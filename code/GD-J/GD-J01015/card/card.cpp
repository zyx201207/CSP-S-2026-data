#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],b[100000],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long d[n+100];
		for(int j=1;j<=n;j++)
		{
			d[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			bool ok=0;
			for(int k=j-1;k>=1;k--)
			{
				if(d[k]==a[j])
				{
					ok=1;
					x=k;
					break;
				}
			}
			if(ok==1){
				for(int k=x;k<j;k++)
				{
					d[k]=0;
				}
			}
			d[j]=a[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(d[j]!=0)
			{
				b[d[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
