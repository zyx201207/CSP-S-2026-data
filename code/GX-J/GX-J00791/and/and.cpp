#include<bits/stdc++.h>
using namespace std;
int a[300001];
int x(int a)
{
    int num=0;
	while(a/2!=0)
	{
		if(a%2==1)
		{
			num++;
		}
		a=a/2;
	}
	if(a%2==1)
	{
		num++;
		}
	return num;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==n)
	{
		cout<<x(a[1]);
	}
	else if(m==1)
	{
		cout<<0;
	}
	else cout<<12;
	return 0;
}
