#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long NUM,n,m,d,q;
	vector<int> stop;//每个地铁口到站点的时间 
	vector<long long> sttt(50005,0);//站点到站台的时间（？） 
	long long num_stop[505];//车站数 
	vector<int> stops[505];//每号地铁的车站顺序 
	vector<long long> time[505];//每个站台到站点的时间 
	cin>>NUM>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		long long x;
		cin>>x;
		stop.push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		num_stop[i]=x;
		for (int i=1;i<=x;i++)
		{
			long long num,tt;
			cin>>num>>tt;
			stops[i].push_back(num);
			time[i].push_back(tt);
			if (sttt[num]==0) sttt[num]=tt;
		}
	}
	for (int i=1;i<=q;i++)
	{
		long long x,y,t=0;
		cin>>x>>y;
		t+=stop[x]+stop[y];
		t+=sttt[x]+sttt[y];
		cout<<t<<endl;
		//BFS 
		/*queue<long long> lst,way;
		vector<long long> memeries;
		lst.push_back(x);
		while (list.empty())
		{
			
			lst.pop();
		}*/
	}
	
	
	return 0;
}
