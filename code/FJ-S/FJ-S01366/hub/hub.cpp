#include<bits/stdc++.h>
using namespace std;
int c,t,n[6],k[6];
int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub,out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		int u[2000010],v[2000010];
		for(int j=1;j<=n[i]-1;j++)
		{
			cin>>u[i]>>v[i];
		}
		cout<<k[i]-1<<"\n";
	 } 
	 
	return 0;
}
