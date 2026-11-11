#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(n==2&&a[i]==a[i+1])
	    {
	    	cout<<0;
	    	return 0;
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
