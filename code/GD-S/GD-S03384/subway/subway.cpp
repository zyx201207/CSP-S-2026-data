#include<bits/stdc++.h>
using namespace std;
vector<int> line[500005];
vector<int> mp[500005];
int b,k,a;
int chu[100005][2];
long long int num=0;
struct sta
{
	int t,w;//t:站厅走到线路的站台所需时间,w:每个地铁站的地铁口走到站厅需要的时间 
	vector<int> linea;
}st[500005];

int dfs(int stas,int ch)
{
	int maxn=9999999;
	if(stas==chu[ch][1])
	{
		return num+=st[stas].w;
	}
	for(int i=0;i<sizeof(mp[stas])-1;i++)
	{
		maxn=min(maxn,min(dfs(mp[stas][i],ch),dfs(mp[stas][i+1],ch)));
	}
	return num+=maxn;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>st[i].w;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>a;
			st[a].linea.push_back(a);
			line[i].push_back(a);
			cin>>st[a].t;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sizeof(line[i])-1;j++)
		{
			mp[line[i][j]].push_back(line[i][j+1]);
			mp[line[i][j+1]].push_back(line[i][j]);
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>chu[i][0]>>chu[i][1];
		dfs(chu[i][0],i);
		cout<<num;
		num=0;
	}
	
	return 0;
}
