#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],b[510],c[510];
bool bb[510];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j]=b[j];
			bb[j]=true;
		}
		for(int j=i;j<=n;j++)
		{
			for(int k=j-1;k>=i;k--)
			{
				if(a[k]==a[j]&&a[j]!=-1)
				{
					for(int l=k;l<j;l++)
					{
						a[l]=-1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(bb[a[j]])bb[a[j]]=false,c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
