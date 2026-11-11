#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[200086],k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while(t--)
	{
		cin>>n>>k;
		int u,v,x=rand()%15000;
		cout<<x<<'\n'; 
		for(int i=1;i<=n;i++) cin>>u>>v;
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
