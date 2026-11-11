#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
int a[500010];
map<int,int>f;
map<int,int>z;
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
 	for(int i=1;i<=n;i++)
 	{
 		f.clear();z.clear();
 		int sum=0;
 		for(int j=i;j<=n;j++)
 		{
 			if(f[a[j]]<=sum&&f[a[j]]!=0)
 			{
 				
 				sum=f[a[j]];
 				z[sum]=a[j];
 			}
 			else
 			{
 				sum++;
 				z[sum]=a[j];
 				f[a[j]]=sum;
 				
 			}
 		}
 		for(int l=1;l<=sum;l++)
 		{
 			ans[z[l]]++;
 		}
 	}
 	for(int i=1;i<=m;i++)
 	{
 		cout<<ans[i]<<" ";
 	}
	return 0;
} 
