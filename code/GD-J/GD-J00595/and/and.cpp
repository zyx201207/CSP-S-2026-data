#include<bits/stdc++.h>
using namespace std;
int a[20001];
int b[20001][20001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				cout<<a[i];
				return 0;
			}
			b[i][j]=a[i]&a[j];
			sum=max(sum,b[i][j]);
		}
	}
	cout<<sum;
	return 0; 
	
	fclose(stdin);
	fclose(stdout);
} 
