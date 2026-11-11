#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,fla;
vector<int> g[1000007];
int d1[1000007],d2[1000007],f[1000007],d[1000007];
vector<int> p;
void dfs(int x,int fa,int* de){
//	cout<<x<<" ";
	de[x]=de[fa]+1;
	for(int y:g[x]){
		if(y!=fa&&!de[y])dfs(y,x,de);
	}
}
void dfs2(int x,int to,int fa){
	if(fla)return ;
	if(x==to){
		fla=1;
		return ;
	}
	for(int y:g[x]){
		if(y!=fa){
			p.push_back(y);
			dfs2(y,to,x);
			if(!fla)p.pop_back();
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		d1[0]=d2[0]=0;
		memset(d,0,sizeof d);
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
//			cout<<x<<" "<<y<<"\n";
			d[x]++,d[y]++;
		}
		int mx=0,ma,mn;
		dfs(1,0,d1);
		for(int i=1;i<=n;i++){
//			cout<<d1[i]<<" ";
			if(d1[i]>mx){
				mx=d1[i];
				ma=i;
			}
		}
		dfs(ma,0,d2);
		mx=0;
		for(int i=1;i<=n;i++){
			if(d2[i]>mx){
				mx=d2[i];
				mn=i;
			}
		}
		p.push_back(mx);
		fla=0;
//		cout<<mx<<" "<<mn<<"\n";
		dfs2(mx,mn,0);
//		for(int x:p)cout<<x<<" ";
		queue<int> q;
		q.push(p[(p.size()+1)/2]);
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				q.push(i);
				f[i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n-k;i++){
			int x=q.front();
			q.pop();
			ans=max(ans,f[x]);
			for(int y:g[x]){
				if(--d[y]==1){
					q.push(y);
					f[y]=f[x]+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
