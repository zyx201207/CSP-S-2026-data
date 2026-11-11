#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],w[500005],mit=1e9;

struct station
{
	int a,t;
}sta[500][500005],req[100005];

station ei,fi;

bool sameline(int a,int b,int l)
{
	bool e=false,f=false;
	for(int j=1;j<=k[l];j++)
	{
		if(a==sta[l][j].a)
		{
			e=true;
			ei.a=l;
			ei.t=j;
		}
		else if(b==sta[l][j].a)
		{
			f=true;
			fi.a=l;
			fi.t=j;
		}
	}
	if(e && f) return true;
	e=false;
	f=false;
	return false;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>sta[i][j].a>>sta[i][j].t;
	}
	for(int i=1;i<=n;i++) cin>>req[i].a>>req[i].t;
	for(int i=1;i<=q;i++)
	{
		int st=w[req[i].a]+w[req[i].t];
		for(int j=1;j<=n;j++)
		{
			if(sameline(req[i].a,req[i].t,i)) mit=min(mit,sta[ei.a][ei.t].t+sta[fi.a][fi.t].t);
		}
		st+=mit;
		cout<<st;
	}
	return 0;
}

