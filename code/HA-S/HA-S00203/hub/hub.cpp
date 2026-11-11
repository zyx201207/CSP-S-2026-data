#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int c,t,n,k,u,v;
vector<int>a[2000005];
int dis[2000005];
bool vis[2000005];
signed main(){
	fre("hub");
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int ans=0;
		vector<int>b;
		for(int i=1;i<=n;i++)b.push_back(a[i].size());
		sort(b.begin(),b.end(),greater<int>());
		for(auto i=b.begin();i<b.end()-k;i++){
			queue<int>q;
			for(int i=1;i<=n;i++){
				dis[i]=0x3fffffff;
				vis[i]=0;
			}
			dis[*i]=0;
			q.push(*i);
			vis[*i]=1;
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int j:a[u])if(!vis[j]){
					vis[j]=1;
					dis[j]=dis[j]+1;
					q.push(j);
				}
			}
			for(auto j=i+1;j<=b.end()-k;j++)ans=max(ans,dis[*j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

