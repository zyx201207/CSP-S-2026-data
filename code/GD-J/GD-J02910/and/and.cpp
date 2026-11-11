#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e8+10;
int a[N];
int n,m,ans,sum;


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sum=0;
	for(int i=0;i<n;i++)
	{
		int s=0;
		for(int j=0;j<n-1&&j!=i;j++)
		{
			if(j<=m-1)
			{
				s=a[i];
				s&=a[j];
			}
			
		}
		sum=max(sum,s);
	}
	cout<<sum;
	return 0;
}
