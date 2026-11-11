#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005],maxa,num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
		if(i==1)
			num=a[i];
		else
			num=num&a[i];
	}
	if(m==1)
		cout<<maxa;
	if(m==2)
	{
		maxa=0;
		int num=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				num=(a[i]&a[j]);
				maxa=max(maxa,num);
			}
		cout<<maxa;
	}
	if(m==n)
		cout<<num;
	return 0;
}
