#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[100000];
int t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		int cnt=1;
		//~ while(b[ii])
		//~ {
			//~ b[ii]=0;
			//~ ii++;
		//~ }
		for(int i=j;i<=n;i++)
		{
			b[cnt++]=a[i];
			for(int k=1;k<cnt-1;k++)
			{
				if(b[k]==a[i])
				{
					cnt=k+1;
					break;
				}
			}
			for(int k=1;k<cnt;k++)
			{
				//~ cout<<b[k]<<" ";
			}
			//cout<<cnt-1<<"\n";
		}
		for(int k=1;k<cnt;k++)
		{
			t[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
