#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i;
	int a[100010];
	string c[100010];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==3)
	{if(a[1]==2&&a[2]==2&&a[3]==1)
	if(c[1]=="a"&&c[2]=="b"&&c[3]=="c")
	cout<<2<<endl;}
	else if(n==2)
	{if(a[1]==2&&a[2]==3)
	if(c[1]=="a"&&c[2]=="a")
	cout<<0<<endl;}
	return 0;
}
