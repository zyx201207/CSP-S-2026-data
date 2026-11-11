#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],zhong[300001],ge[300001],ji,cun[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(zhong[a[j]]==0)
			{
				ji+=1;
				zhong[a[j]]+=1;
				cun[ji]=a[j];
			}
			else
			{
				long long k=0;
				for(int h=1;h<=ji;h++)
				{
					if(cun[h]==a[j])
					{
						k=h;
						cun[h]=0;
					}
				}
				for(int h=k+1;h<=ji;h++)
				{
					cun[h]=0;
				}
				ji=k;
				ji+=1;
				cun[ji]
		    }
		}
		for(int i=1;i<=ji;i++)
		{
			ge[cun[i]]+=1;
			cun[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ge[i]<<" ";
	}
	return 0;
 } 
//4 3
//1 2 1 3
