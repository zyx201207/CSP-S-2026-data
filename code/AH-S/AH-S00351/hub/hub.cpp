#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

#define int long long
const int N=1e6+5;
int c,t,i,n,k,fa[N],u,v,de[N];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=1;i<n;i++)
		{
			if(!fa[u])fa[u]=v;
			else fa[v]=u;
		}
	}
}
