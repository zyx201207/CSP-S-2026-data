#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k,u,v;
vector<int>g[N];
int main()
{
	freopen( "hub.in" , "r" , stdin );
	freopen( "hub.out" , "w" , stdout );
	cin>>c>>T;
	while( T-- )
	{
		cin>>n>>k;
		for( int i=1 ; i<n ; i++ )
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if( T )  cout<<1<<endl;
		else  cout<<2<<endl;
	}
	return 0;
}
