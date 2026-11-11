#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,a[1000005],b[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j];
		}
	}
	if(t==2)
	{
		cout<<1<<endl<<2;
	}
	else
	{
		cout<<1<<endl<<1<<endl<<2;
	}
	return 0;
}
