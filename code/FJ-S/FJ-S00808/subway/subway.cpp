#include<bits/stdc++.h>
using namespace std;
using pll=pair<long long,pair<long long,bool> >;
const int N=5e5+510;
int c,n,m,d,q;
long long w[N],D[N][2];
vector<pair<int,long long> >e[N];
priority_queue<pll,vector<pll>,greater<pll> >Q;
int main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	    cin>>w[i];
	for(int i=1;i<=m;i++)
	{
        int k;
        cin>>k;
        while(k--)
        {
            long long a,b;
            cin>>a>>b;
            e[a].push_back({n+i,b});
            e[n+i].push_back({a,b});
		}
	}
	n+=m;
	while(q--)
	{
		int x,y;
	    cin>>x>>y;
	    long long ans=w[x]+w[y]; 
		for(int i=1;i<=n;i++)
		    D[i][0]=D[i][1]=-1;
		while(!Q.empty())
		    Q.pop(); 
	    Q.push({0,{x,0}});
	    Q.push({0,{y,1}});
		while(!Q.empty())
		{
	        pll tmp=Q.top();
		    Q.pop();
		    if(D[tmp.second.first][tmp.second.second]!=-1)
			    continue;
			D[tmp.second.first][tmp.second.second]=tmp.first;
			if(D[tmp.second.first][!tmp.second.second]!=-1)
		    {
		    	ans+=D[tmp.second.first][tmp.second.second]+D[tmp.second.first][!tmp.second.second];
		    	break;
		    }
			for(int i=0;i<e[tmp.second.first].size();i++)
			    if(D[e[tmp.second.first][i].first][tmp.second.second]==-1)
			        Q.push({tmp.first+e[tmp.second.first][i].second,{e[tmp.second.first][i].first,tmp.second.second}});
		} 
		cout<<ans<<endl;
	}
} 
