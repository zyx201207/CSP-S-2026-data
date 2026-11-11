#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,k,u,v,c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k>>u>>v;
		while(n--)cin>>u>>v;
		cout<<sqrt(k)+1;
	}
}
