#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005],L[200005],vis[200005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=a[i-1])
			f=1;
	}	
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=m)
				vis[i]++;
		}
		for(int i=1;i<=m;i++)
			cout<<vis[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int len=0;
		for(int j=i;j<=n;j++)
		{
			if(L[a[j]]==0)
			{
				len++;
				b[len]=a[j];
				L[a[j]]=len;
			//	cout<<b[len]<<" "<<L[a[j]]<<endl;
			}
			else
			{
				len=L[a[j]];
			//	cout<<L[a[j]]<<" ";
				for(int k=j-1;k>L[a[j]];k--)
				{
					L[b[k]]=0;
					b[k]=0;
				}
			//	L[a[j]]=j;
			}
			//for(int i=1;i<=len;i++)
			//	cout<<b[i]<<" ";
			//cout<<endl;
			//cout<<L[a[j]]<<" ";
		}
	//	cout<<endl;
		for(int j=1;j<=len;j++)
		{
		//	cout<<b[j]<<" ";
			vis[b[j]]++; 	
			b[j]=0;
		}
		for(int j=1;j<=n;j++)
			L[a[j]]=0;
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)
		cout<<vis[i]<<" ";
	return 0;
 }


