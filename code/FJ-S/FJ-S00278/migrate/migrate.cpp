#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,t;
	int a[200005];
	cin>>n>>t;
	if(t==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(n<4)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	int x;
	x=n-t-1;
	cout<<x;
	return 0;
	
}
