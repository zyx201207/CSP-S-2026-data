#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
int main( )
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	
	char o=b[1];
	int t=0;
	for(int i=1;i<=n;i++)if(b[i]!=o)t=1;
	if(t!=1)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}

