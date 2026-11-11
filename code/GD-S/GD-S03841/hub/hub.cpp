#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[1010000];
int zs[1010000],zx;
struct node{
	int x,lg;
};
void dfs(int x,int fa){
	zs[x]=1;
	for(auto p:v[x]){
		if(p==fa)continue;
		dfs(p,x);
		zs[x]+=zs[p]; 
	}
	if(zs[x]-1==n/2)zx=x;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear(),zs[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n==k){
			cout<<0<<'\n';
			continue;
		}
		dfs(1,0);
		queue<node> q;
		vector<bool> b(n+1,0);
		int cs=0,ans=0;
		for(int i=1;i<=n;i++){
			if(v[i].size()==1){
				q.push({i,1});
				cs++;
				b[i]=1;
			}
		}
		if(cs>=n-k){
			cout<<"1\n";
			continue;
		}
		b[zx]=1;
		cs++;
		q.push({zx,1});
		bool f=0;
		while(!q.empty()){
			node t=q.front();q.pop();
			ans=max(ans,t.lg);
			for(auto p:v[t.x]){
				if(!b[p]){
					b[p]=1;
					cs++;
					q.push({p,t.lg+1});
					if(cs+k==n){
						ans=max(ans,t.lg+1);
						f=1;
						break;
					}
				}
			}
			if(f)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

