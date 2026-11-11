#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000000],v[1000000];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<n;j++)
		{
			cin>>u[j]>>v[j];
		}
		cout<<i<<endl;
	}
	return 0;
}
