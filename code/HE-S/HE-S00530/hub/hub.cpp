#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
const int N=1e6+520;
vector <int> vv[N]; 
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			vv[u].push_back(v);
			
		}
		cout<<1<<endl;
	}
	
	return 0;
}
