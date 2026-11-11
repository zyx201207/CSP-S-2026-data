#include<bits/stdc++.h>
using namespace std;
int u[10005];
int v[10005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
		cin>>v[i];
	}
	cout<<ans;
	
	return 0;
}
