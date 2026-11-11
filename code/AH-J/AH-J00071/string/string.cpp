#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()	
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int cnt;
	cin>>n;
	int a;
	char b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
	}
	for(int j=1;j<=n/2;j++)
	{
		if(a[j]!=a[n])
		{
		cnt++;
		n--;
		}
		else
		{
			continu;
		}
	}
	cout<<cnt;
	return 0;
}
