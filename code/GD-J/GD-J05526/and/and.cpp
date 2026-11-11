#include<bits/stdc++.h>
using namespace std;
int A[1000000],C[10000000];
int B[10000000];
bool V[10000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		k=max(k,A[i]);
	}
	if(m==1)
	{
		cout<<k;
	}
	else
	{
		k=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				k=max(k,A[i]&A[j]);
			}
		}
		cout<<k;
	}
	
	
	
	 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
