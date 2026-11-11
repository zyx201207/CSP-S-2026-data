#include<bits/stdc++.h>
#define int long long 
using namespace std;
int id,T,n,k,ans,fa[35],x[100005],y[100005],dis[35];
bool vis[35],Vis[35];
vector<int> v[100005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int check(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vis[i]==vis[j]&&(!vis[i]))
				fa[find(i)]=find(j);
	int cnt=0;
	for(int i=1;i<n;i++)
		if(vis[x[i]]==vis[y[i]]&&vis[x[i]])
			fa[find(x[i])]=find(y[i]);
	for(int i=1;i<=n;i++) Vis[i]=0;
	for(int i=1;i<=n;i++) Vis[find(i)]=1;
	for(int i=1;i<=n;i++) cnt+=Vis[i];
	return cnt;
}
queue<int> q;
void solve(){
	scanf("%lld%lld",&n,&k),ans=INT_MAX;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<n;i++)
		scanf("%lld%lld",&x[i],&y[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
	if(id==1||id==2||id==3){
		for(int State=0;State<(1<<n);State++){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if((State>>(i-1))&1)
					vis[i]=1,cnt++;
				else
					vis[i]=0;
			if(cnt>k) continue;
			if(check()<=3){
				for(int i=1;i<=n;i++) dis[i]=INT_MAX;
//				for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//				cout<<endl;
				for(int i=1;i<=n;i++)
					if(vis[i])
						q.push(i),dis[i]=0;
				while(!q.empty()){
					int x=q.front();
					q.pop();
					for(int y:v[x]){
						if(dis[y]>dis[x]+1){
							dis[y]=dis[x]+1;
							q.push(y);
						}
					}
				}
				int Now=0;
				for(int i=1;i<=n;i++) Now=max(Now,dis[i]);
				ans=min(ans,Now);
			}
		}
		printf("%lld\n",ans);
		return;
	}
//	if(id==13||id==14){
		if(k==1){
			printf("%lld\n",(n-1)/2);
			return;
		}
		int ans=(n-k)/4;
		if((n-k)%4) ans++;
		printf("%lld\n",ans);
		return;
//	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&id,&T);
	while(T--) solve();
	return 0;
}
/*
1 2
5 2
1 2
2 3
3 4
4 5
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
