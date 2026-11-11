#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
char c[100010];
char d[100010];
int m=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
//	while(cin>>a>>c)
//	{
//		d[sum]=c;
//		sum++;
//	}
//	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		{
			d[j]=c[i];
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<d[i]<<endl;
//	}
//	for(int i=0;i<sum;i++)
//	{
//		cout<<d[i];	
//	}
//	for(int i=0;i<m;i++)
//	{
//		for(int )
//	}
	cout<<0;
	return 0;
}
