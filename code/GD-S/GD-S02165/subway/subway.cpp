#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50001],ans=INT_MAX;
int k;
bool b[50001];
struct sub{
	int a[50001],t[50001];
	int k;
}s[501];
int cmp(sub x,sub y)
{
	return x.t<y.t;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		s[i].k=k;
		for(int j=1;j<=k;j++)
		{
			cin>>s[i].a[j]>>s[i].t[j];
		}
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=q;i++)
	{
		ans=0;
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
				ans+=2*(s[j].t[1]);
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans;
	}
	return 0;
}
