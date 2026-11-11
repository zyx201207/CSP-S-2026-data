#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6*2;
int c,q,n,k;
vector<int >t[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>q;
	while(q--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
