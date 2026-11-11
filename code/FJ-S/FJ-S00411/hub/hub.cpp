#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
long long c,t,n,k;
vector<int>a[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<rand()%n<<endl;
	}
	return 0;
}

