//GZ-S00102 遵义市第五中学 罗子懿
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const long long MAXN = 1e4+10;
long long st[MAXN],fin[MAXN];
struct subway
{
	int t,T[MAXN],w[MAXN];
}node[MAXN];
void input()
{
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>node[i].t;
	for(int i = 1,t,p;i<=n;i++)
	{
		cin>>t;
		for(int j = 1,a,b;j<=t;j++)
		{
			cin>>a>>b;
			node[a].w[i]=114514;
			node[a].T[i]=b;
		}
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>st[i]>>fin[i];
	}
}
/*int minT(int x)
{
	int r = INT_MAX;
	int l = sizeof(node[x].T);
	for(int i = 1;i<=l;i++)
	{
		if(node[x].w[i])
		r = min(r,node[x].T[i]);
	}
	return r;
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	for(int i = 1;i<=q;i++)
	{
		int s = st[i],f = fin[i],ans = 0;
		ans+=node[s].t;
		
	}
	
	
	
	return 0;
}
