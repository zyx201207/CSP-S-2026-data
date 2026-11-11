#include<bits/stdc++.h>
using namespace std;
unsigned long long a[50001][100001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	a[2][1]=1;
	a[2][2]=1;
	int p=1;
	for(int i=2;i<=50000;i++)
	{
		for(int j=1;j<=i+p;j++)
		{
			if(i+p-3==j)
			{
				a[i][j]=1;				
			}	
			else
			{
				a[i][j]=a[i-1][j]+1;
			}
		}	
		p+=1;
	}
	int c,t;
	cin>>c>>t;
	
	for(int u=1;u<=t;u++)
	{
		int n,k;
		cin>>n>>k;
		cout<<a[n/2+1][k]<<endl;
	}
	return 0;
}
