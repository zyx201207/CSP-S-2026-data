#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>e[1000010];
bool v[1000010];
int mx;
bool dfs(int x,int fa,int c){
	mx=max(mx,c);
	for(int y:e[x]){
		if(y!=fa)dfs(y,x,(v[x]?0:c+1));
	}
}
int fa[1000010];
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _,T,n,k,x,y;
	cin>>_>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans=1e9;
		for(int s=0;s<(1<<n);s++){
			if(__builtin_popcount(s)!=k)continue;
			for(int i=1;i<=n;i++){
				if(s&(1<<(i-1)))v[i]=1;
				else v[i]=0;
			}
			mx=0;
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int x=1;x<=n;x++){
				for(int y:e[x]){
				if(!(s&(1<<(x-1))))continue;
				if(!(s&(1<<(y-1))))continue;
					fa[fd(x)]=fd(y);
				}
			}
			int cc=0;
			for(int x=1;x<=n;x++){
				if(!(s&(1<<(x-1))))continue;
				if(fa[x]==x)cc++;
			}
			if(cc>2)continue;
			for(int i=1;i<=n;i++)dfs(i,0,0);
//			if(mx==1){
//				for(int i=1;i<=n;i++){
//				if(s&(1<<(i-1)))cout<<i<<"\n";
//				}
//			}
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
