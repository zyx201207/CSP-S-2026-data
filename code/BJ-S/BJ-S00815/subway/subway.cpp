#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ak[305],tk[305];
long long minx,w[500005],disk[305][305];
void work1()
{
	memset(disk,0x3f3f3f,sizeof(disk));
	while(n--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>ak[i]>>tk[i];
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++) disk[ak[i]][ak[j]]=disk[ak[j]][ak[i]]=min(disk[ak[i]][ak[j]],(long long)tk[i]+tk[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int t=1;t<=m;t++) disk[i][j]=min(disk[i][j],disk[i][t]+disk[t][j]);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<disk[x][y]+w[x]+w[y]<<"\n";
	}
}
struct node
{
	int xk;
	long long wk;
};
vector<node> tkk[1005];
long long fkk[1005];
queue<pair<int,long long>> qkk;
void dfskk(int u,int f)
{
	minx=0x3f3f3f3f;
	memset(fkk,-1,sizeof(fkk));
	qkk.push(make_pair(u,0));
	fkk[u]=0;
	while(!qkk.empty())
	{
		int v=qkk.front().first;
		long long s=qkk.front().second;
		qkk.pop();
		if(v==f)
		{
			minx=min(minx,s);
			continue;
		}
		for(int i=0;i<(int)tkk[v].size();i++)
		{
			int vv=tkk[v][i].xk;
			long long sk=s+tkk[v][i].wk;
			if(sk>=fkk[vv]&&fkk[vv]!=-1) continue;
			fkk[vv]=sk;
			qkk.push(make_pair(vv,sk));
		}
	}
}
void work2()
{
	while(n--)
	{
		int k,u,v,x1,x2;
		cin>>k;
		cin>>u>>x1>>v>>x2;
		tkk[u].push_back({v,x1+x2});
		tkk[v].push_back({u,x1+x2});
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dfskk(x,y);
		cout<<w[x]+w[y]+minx<<"\n";
	}
}
void work3()
{
	
}
long long fk[3][500005];
void work4()
{
	if(n==1)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			fk[1][x]=y;
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+fk[1][x]+fk[1][y]<<"\n";
		}
		return;
	}
	for(int i=1;i<=2;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			fk[i][x]=y;
		}
	}
	minx=1e18;
	for(int i=1;i<=m;i++)
	{
		if(fk[1][i]==0 || fk[2][i]==0) continue;
		minx=min(fk[1][i]+fk[2][i],minx);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		if(fk[1][x]!=0 && fk[1][y]!=0)  ans=min(ans,fk[1][x]+fk[1][y]);
		if(fk[2][x]!=0 && fk[2][y]!=0)  ans=min(ans,fk[2][x]+fk[2][y]);
		if(fk[1][x]==0 && fk[1][y]!=0) ans=min(ans,fk[2][x]+fk[1][y]+minx);
		if(fk[2][x]==0 && fk[2][y]!=0) ans=min(ans,fk[1][x]+fk[2][y]+minx);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c<=6) work1();
	else if(c<=11) work2();
	else if(c<=19) work3();
	else if(c<=21) work4();
	return 0;
}
