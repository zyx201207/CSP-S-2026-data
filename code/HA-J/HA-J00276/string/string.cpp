#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
int main()
{
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
		cout<<0;
	if(n==2)
	{
		if(a[1]==a[2]&&c[1]==c[2])
			cout<<0;
		else
			cout<<1;
		}
	if(n==3)
	{
		if(a[1]==a[2]==a[3]&&c[1]!=c[2]&&c[2]!=c[3]&&c[1]==c[3])
			cout<<1;
		else
			cout<<2;
	}
	return 0;
}
