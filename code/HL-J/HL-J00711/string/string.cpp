#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char c[30];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==c[i])
		{
			cout<<"0";
			break;
		}
		if(a[1]>a[2]);
		{
			cout<<a[2];
			break;
		}
		if(a[2]>a[1]);
		{
			cout<<a[1];
			break;
		}
	}
	return 0;
}