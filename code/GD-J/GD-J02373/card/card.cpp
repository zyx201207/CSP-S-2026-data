#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[300005];
long long last[300005];
bool b[500005];
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
		memset(last,-1,sizeof(last));
		memset(b,true,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			if(last[j]==-1) last[j]=j;
			else
			{
				for(int k=last[j];k<=j;k++)
				{
					b[k]=false;
				}
				last[j]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]==true) sum[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	cout<<endl;
	return 0;
}
