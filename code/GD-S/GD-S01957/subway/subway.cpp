#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
vector<node> g[505];
int c,n,m,d,q;
int w[500005];
int walk(int x,int y)
{
	int cnt=w[x]+w[y];
	for(int i=1;i<=n;i++)
	{
		bool m1=0,m2=0;
		for(int j=1;j<=g[i].size();j++)
		{
			if(g[i].a==x) m1=true;
			if(g[i].a==y) m2=true;
		}
		if(m1&&m2) cnt+=g[i].t+g[i].t;
		{
			cnt+=g[i]
		}
	}
	return cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;	
		cin >> k;
		for(int j=1;j<=2*k;j++)
		{
			cin >> g[i].a >> g[i].b;
			g[i].push_back(g[i].a,g[i].b);
		}
	}
	long long sum=0;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin >> x >> y;
		cout<<walk(x,y)<<endl;
	}
	return 0;
}
