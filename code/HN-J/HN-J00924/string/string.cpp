#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,a[1000005],ans;
    string m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>m;
	}
	if(n=1)
	{
	cout<<0;	
	}
	if(n==2)
	{
		sort(a+1,a+n+1);
		cout<<a[1];
	}
	return 0;
 } 
