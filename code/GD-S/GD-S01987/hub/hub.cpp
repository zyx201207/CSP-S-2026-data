#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;

struct edge
{
	int u,v,w;
}e[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>e[i].u>>e[i].v;
			
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
