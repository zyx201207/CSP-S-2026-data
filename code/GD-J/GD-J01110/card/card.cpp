#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],x[500005],t[300005];
int main()
{
	freopen("card.in","r",stdin);//¸Ä 
	freopen("card.out","w",stdout);//¸Ä 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		for(int j=i;j<=n;j++)
		{
			if(a[x[j]]>0) 
			{
				for(int k=a[x[j]];k<=j;k++)
					a[x[k]]=0;
			}
			a[x[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(a[j]>0) t[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	
	return 0;	
} 
