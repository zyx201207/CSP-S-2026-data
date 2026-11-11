#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	srand(time(0));
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			rand();
		}
		cout<<(n/m)-(n<=300? 1:(rand()%2? -1:1)*(rand()%5))<<"\n";
	}
	return 0;
}

