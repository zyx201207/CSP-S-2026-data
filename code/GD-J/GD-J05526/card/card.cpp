#include<bits/stdc++.h>
using namespace std;
int A[10000000],C[10000000];
int B[10000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(B[A[j]]==0)
			{
				C[A[j]]+=1;
				B[A[j]]=j;
			}
			else
			{
				for(int u=1;u<=m;u++)
				{
					if(B[u]>B[A[j]])
					{
						B[u]=0;
						C[u]-=1;
					}
				}
			}
			
		}
		for(int j=1;j<=m;j++)
		{
			B[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<C[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
