#include<bits/stdc++.h>
using namespace std;
long long C,t,m,n,i,j,a[500005],k,f[500005],s;
vector<long long> b[500005];
queue<int> q;
void zdl(long long u,long long v)
{
	for(int i=1;i<=v;i++)
	{
		f[i]=1;
	}
	q.push(u);
	while(!q.empty())
	{
		long long q1=q.front();
		q.pop();
		if(q1>=v) continue;
		for(auto o:b[q1])
		{
			if(o<q1) continue;
			f[o]+=f[q1];
			//cout<<f[q1]<<' ';
			q.push(o);
		}
	}
	//return f[v];
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>t;
	while(t--)
	{
		cin>>n>>k;
		s=0;
		for(i=1;i<=n;i++) b[i].clear();
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			for(j=1;j<i;j++)
			{
				if(a[i]-a[j]>k) continue;
				b[a[j]].push_back(a[i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				zdl(a[j],a[i]);
				
			}
			if(f[a[i]]==2) s++;
			//cout<<f[a[i]]<<' ';
		}
		cout<<s<<'\n';
	}	
	return 0;
}
