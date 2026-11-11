#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b; 
}
int a[1000005];
int b[1000005];	
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0,x=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		x=0;
		s=0;
		while(s<=m)
		{
			x++;
			s+=a[x]-a[1];
		}
		x--;
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=a[x])
				b[i]++;
		}	
	}
	sort(b+1,b+1+n,cmp);
	cout<<b[n];
	return 0;
 } 
