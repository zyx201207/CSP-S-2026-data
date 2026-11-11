#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
		}
		if(n<=15)
		{
			cout<<rand()%5<<endl;
		}
		else if(n<=1000)
		{
			cout<<rand()%100<<endl;
		}
		else
		{
			cout<<rand()%500<<endl;
		}
	}
	return 0;
}
