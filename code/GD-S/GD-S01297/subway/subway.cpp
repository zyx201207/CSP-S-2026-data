#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int tes,qua,sta,lim,pla,wal[N],st,en,res;
struct Sta{int aim,cos,id;}ins[N];
vector<Sta>gra[N];
void dfs(int poi,int tim,int id)
{
	if(poi==en)
	{
		res=min(res,tim);
		return;
	}
	for(auto m:gra[poi])
	{
		if(m.id==id)return;
		m.id=id;
		int timi=tim+m.cos+wal[poi];
		dfs(m.aim,timi,id);
	}
	return; 
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tes>>qua>>sta>>lim>>pla;
	for(int m=1;m<=sta;m++)cin>>wal[m];
	for(int m=1;m<=qua;m++)
	{
		int num;
		cin>>num;
		while(1)
		{
			while(1)
			{
				while(1)
				{
					int y;
				}
			}
		 } 
		for(int m=1;m<=num;m++)
		{
			int x,y;
			cin>>x>>y;
			ins[m].aim=x,ins[m].cos=y;
		}
		for(int m=1;m<=num;m++)
		{
			for(int n=1;n<=num;n++)
			{
				if(n==m)continue;
				gra[ins[m].aim].push_back({ins[n].aim,ins[m].cos,0});
				gra[ins[n].aim].push_back({ins[m].aim,ins[n].cos,0});
			}
		}
	}
	for(int m=1;m<=pla;m++)
	{
		cin>>st>>en;
		res=2e9;
		dfs(st,0,m);
		cout<<res<<"\n";
	}
	return 0;
}
