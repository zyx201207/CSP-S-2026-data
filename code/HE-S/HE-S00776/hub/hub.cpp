#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,m,k,u,v,r;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		int way[n+56][n+65];
		for(int j=1;j<n;j++)
		{
			cin>>u>>v;
			way[u][v]++;
		}
		cout<<n/(k+1)<<endl;
	}
	return 0;
} 
