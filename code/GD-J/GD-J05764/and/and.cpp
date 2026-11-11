#include<bits/stdc++.h>
using namespace std;


bool cmp(int x ,int y)
{
	return x > y;
 } 
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	int a[n + 5] = {} ;
	cin >> n >> m;
	for(int i = 1;i<= n;i++)
	{
		cin >> a[i];
	}
	sort(a +1 ,a+n+1,cmp);
	long long ma = -123;
	long long sum =0;
	for(int i = 1;i<=n;i++)
	{
		sum =0;
		int g = 1,k;
		for(int j = i ;j<=m;j++)
		{
			if(g > n)
			{
				k=1;
				
			}
			if(g==1)
			{
				g = j;
				k = j;
				sum = a[k];
			}
			sum= sum & a[k];
			k++;
			g++;
			
		}
		ma = max(sum ,ma);
	}
	cout  << ma;
	 
	 
	 
	
	
	return 0;
 } 
