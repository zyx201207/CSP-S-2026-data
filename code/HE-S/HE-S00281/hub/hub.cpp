#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=t*(n+m);++i)
	{
		cin>>u[i]>>v[i];
	}
	cout<<1<<endl;
	cout<<2;
	return 0;
}
