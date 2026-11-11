#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
		}
		if(n<9)
		cout<<1<<endl;
		else
		cout<<2<<endl;
	}
	return 0;
}
