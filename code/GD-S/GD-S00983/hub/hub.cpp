#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
vector<int> G[N];
bool v=1;
int dep[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto i:G[x]){
		if(i==fa) continue;
		dfs(i,x);
	}
	return ;
}

void solve(){
	memset(dep,0,sizeof(dep));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=N;i++) G[i].clear();
	int x,y;
	int p=n/2;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		if(!((n&1 && i<=p && x==i && y==i+1)||(n&1 && i>p && x==i-p && y==i+1))) v=0; 
	}
	if(v) {
		//变成一条链带了点挂件，挂件基本可以无视，但1的挂件要掰过来使链长度+1
		//最终链的长度变成p+1，上共有n个连接线，问题变为在数轴上的情况
		p=n/2+1;
	}
	else{
		dfs(1,0);
		int u=0,mx=0;
		for(int i=1;i<=n;i++){
			if(mx<dep[i]) u=i,mx=dep[i];
			dep[i]=0;
		}
		dfs(u,0);
		for(int i=1;i<=n;i++){
			p=max(p,dep[i]);//不然的话p就当直径咯，反正我也不会... 
		}
		p--;
	}
	ll ans=p/3;
	k-=p%3;k-=2;
	ans-=k/3;
	printf("%d\n",&ans);
	//17:47 
	//不是为什么啊，为什么这玩意没输入要跑6秒多啊 
	//这真不是我的问题吧，是我的问题我认了啊
	//别搞我啊别搞我啊 
	//妖魔鬼怪快离开,妖魔鬼怪快离开...... 
	return ;
}


int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c;
	cin>>c;
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}	
	
	
	return 0;
}
