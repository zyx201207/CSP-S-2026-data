#include<bits/stdc++.h>
using namespace std;
char a[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,num=0;
	cin>>n;
	int c;
	char d;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>d;
		for(int j=1;j<=c;j++)
		{
			sum++;
			a[sum]=d;
		}
	}
	for(int i=1;i<=(sum+1)/2;i++)
	{
		if(a[i]!=a[sum-i+1])
		num++;
	}
	cout<<num;
	return 0;
}
