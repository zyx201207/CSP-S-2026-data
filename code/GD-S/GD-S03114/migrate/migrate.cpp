#include <bits/stdc++.h>

using namespace std;

vector<pair<long long,int>> adj[2000005];//Â·¾¶£¬±àºÅ 
long long x[2000005];
long long c,t;
void dis(int x)
{
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(x[j]-x[i]<=d) adj[i].emplace_back(x[j]-x[i],j);
			}
		}
	}
	dis
	return 0;
}
