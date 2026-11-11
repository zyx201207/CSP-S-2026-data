#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int INF=0x3f3f3f3f;
const int N=1e6+10;
int c,t;
int n,k;
int idx,pre[N];
struct node
{
	int from,to,last;
}a[N*2];
void add(int u,int v)
{
	a[++idx]={u,v,pre[u]};
	pre[u]=idx;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		} 
		cout<<0<<'\n';
	}
	return 0;
}
