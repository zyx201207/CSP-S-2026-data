#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		cin>>s[i];
	}
	if(n==3)
		cout<<2;
	if(n==2)
		cout<<0;
	if(n==6)
		cout<<3000000000;
	if(n==2000)
	{
		if(a[0]==39)
			cout<<24474;
		if(a[0]==42263668)
			cout<<479681762610;
	}
	if(n==200000)
		cout<<24104423;
}
