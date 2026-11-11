#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5000005;
ll c,t,n,k,u[N],v[N],r[N],pp[N];
queue <pair<ll,ll>>q;
int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)scanf("%lld %lld",&u[i],&v[i]);
		memset(pp,0,sizeof pp);
		map<ll,map<ll,ll>>p;
		for(int i=1;i<n;i++)
		{
			p[u[i]][v[i]]=1;
			p[v[i]][u[i]]=1;
			pp[v[i]]++;
			pp[u[i]]++;
		} 
		memset(r,0,sizeof r);
		ll an=0;
		for(int i=1;i<=n;i++)
		{
				if(pp[i]==1&&r[i]==0)
				{

					q.push({i,1});
					while(!q.empty())
					{
						ll to=q.front().first;
						r[to]=q.front().second;
						an=max(an,r[to]);
						
						for(int k=1;k<=n;k++)
						{
							if((p[to][k]||p[k][to])&&r[k]==0)
							{
								q.push({k,1+q.front().second});
							}
						}
						q.pop();
					}
				}
		} 
		cout<<ceil(1.0*an/(k*2+1))<<"\n";
	}
	return 0;
}//0 2 5 2 1 2 2 3 3 4 4 5 10 3 1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10
