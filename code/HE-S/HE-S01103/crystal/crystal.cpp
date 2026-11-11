#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int w; 
	int count=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
/*	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		count=0;
		for(int j=1;j<=n;j++)
		{
			a[i]==j;
			count++;
		}
		b[i]=count;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i+1]-b[i]<b[i+3]-b[i+2])
		{
			w=b[i+1];
		}
		else
		{
			w=b[i+3];
		}
	}  */ 
	if(m>=n*(n-1)/2)
	{
		cout<<n<<endl;
	else
	{
		cout<<2+(m/5)<<endl;
	}
	return 0;
}
