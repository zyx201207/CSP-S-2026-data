#include <bits/stdc++.h>
using namespace std;
int N,M,A[1000005],maxx,Ans,maxy,Z,B[1000005],C[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>N>>M;
	Z=N;
	for (int i=1;i<=N;i++)
	{
		cin>>A[i];
		B[i]=A[i];
	}
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j++)
		{
			B[j]=A[j];
		}
		for (int j=i;j<=N;j++)
		{
			for (int k=1;k<j;k++)
			{
				if (B[j]==B[k])
				{
					for (int q=k;q<j;q++)
					{
						B[q]=B[q+j-k];
						Z=Z-j+k;
					}
				}
			}
		}
		for (int j=1;j<=N;j++)
			C[B[j]]++;
	}
	for (int i=1;i<=N;i++)
	{
		cout<<C[i];
	}
	return 0;
}

