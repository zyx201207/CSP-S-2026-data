#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",strin);
	freopen("string.out","w",strout);
	int n,a[200005],s=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		c[0]=c[1];
		if(c[i]!=c[i-1])
		{
			s++;
		}
	}
	long long num=0;
	if(n==1 || s==0)
	{
		cout<<"0"; 
	}
	else if(n==2 && c[1]!=c[2])
	{
		cout<<min(c[1],c[2]);
	}
	else
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			num+=a[i];
		}
		cout<<num/2;
	}
	return 0;
}
