#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,e,k,z,p,st,en;
long long w[500005],num=0;
struct xl{
	int zt;
	long long t;
};
vector <xl> v[505];
queue <int> q;
bool f[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>e;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>z>>p;
			v[i].push_back({z,p});
		}
	}
	for(int i=1;i<=e;i++)
	{
		cin>>st>>en;
		q.push(st);
		f[st]=1;
		while(!q.empty())
		{
			int h=q.front();
			for(auto y:v[h])
			{
				if(f[y.zt]==0)
				{
					q.push(y.zt);
					f[y.zt]=1;
				}
			}
			cout<<h<<endl;
			q.pop();
		}
	}
	return 0;
}
