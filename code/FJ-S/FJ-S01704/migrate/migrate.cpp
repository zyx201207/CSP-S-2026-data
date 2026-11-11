#include<iostream>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;

const int maxn=2000005;
int n,d,x[maxn];
bitset<maxn> vis;
int minrou,roucnt;

void dfs(int u,int goal,int len){
	if(u==goal){
		if(len==minrou) roucnt++;
		if(len<minrou){
			roucnt=1; minrou=len;
		}
		return;
	}
	vis[u]=1;
	for(int vv=1;vv<=n;vv++){
		if(vis[vv]||abs(x[u]-x[vv])>d) continue;
		dfs(vv,goal,len+1);
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		vis.reset();
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				minrou=1e9; roucnt=1;
				dfs(u,v,0);
				if(roucnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
