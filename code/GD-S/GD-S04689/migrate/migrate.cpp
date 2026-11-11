#include<bits/stdc++.h>
using namespace std;
#define int long long 
const signed N=5e3+10;
int c,t,n,D,ans;
int a[N];
int d[N],tot[N],vis[N];
vector<int > e[N];
void dij(int s)
{
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	d[s]=0,tot[s]=1,vis[s]=1;
	while(!q.empty())
	{
		pair<int,int > now=q.top(); q.pop();
	//	cout<<now.first<<" "<<now.second<<endl;
		for(int i=0;i<e[now.second].size();i++)
		{
			int to= e[now.second][i];
		//	cout<<"  "<<now.second<<"->"<<to<<endl;
		//	for(int j=1;j<=n;j++) cout<<j<<" "<<tot[j]<<" "<<vis[j]<<" "<<d[j]<<endl;
			if(vis[to]){
				if(d[now.second]+1 == d[to]){
		//			cout<<"noup "<<now.second<<"->"<<to<<endl;
					tot[to]++; 
				}
				continue;
			}
			vis[to]=1;
			if(d[now.second] + 1 < d[to])
			{
				d[to]=d[now.second] + 1;
				tot[to]=1;
				q.push({d[now.second]+1,to});
			}
			//q.push({d[now.second]+1,to});
		}
	}
}

signed main()
{	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
	//	cout<<"T                                          :"<<t<<endl;
		cin>>n>>D;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=3) {
			cout<<0<<endl;
			continue;
		}
		for(int i=1,j=i+1;i<=n;i++)
		{
			for(int j=i+1;j<=n && a[j]-a[i]<=D;j++)
			{
				e[i].push_back(j);
				e[j].push_back(i);
			//	cout<<"con"<<i<<" "<<j<<endl; 
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) tot[j]=vis[j]=0,d[j]=1e10;
			dij(i);
			for(int j=1;j<=n;j++){
				if(tot[j]==2){
					ans++;
				//	cout<<i<<" "<<j<<endl;
				} 
			}  
			//cout<<i<<" "<<ans<<endl; 
		//	for(int j=1;j<=n;j++) cout<<j<<" "<<tot[j]<<" "<<vis[j]<<" "<<d[j]<<endl;
		}
		cout<<ans/2<<endl; 
		ans=0;
		for(int i=1;i<=n;i++) e[i].clear();
	}  
	return 0; 
}
