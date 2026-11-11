#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[1919810],dis[1919810],x[1919810],c,t,n,d;
struct node{
	int u,dis;
};
int bfs(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.dis>dis[u.u])continue;
		vis[u.u]++;
		dis[u.u]=u.dis;
		int l=lower_bound(x+1,x+n+1,x[u.u]-d)-x;
		//cout<<u.u<<" "<<l<<'\n';
		for(int i=l;x[i]-x[u.u]<=d&&i<=n;i++){
			if(u.dis+1<=dis[i]){
				q.push({i,u.dis+1});
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(vis[i]==2)cnt++;
	//cout<<s<<'\n';
	return cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++)ans+=bfs(i);
		cout<<ans/2<<'\n';
	}
	return 0;
}
//16:15 224pts
/*
	1  1111111	   111     111111  1
	 1111111	   111      1111111
	  111111 1     111 	    111111
	  111111  1    111	    111111
	11111111   1   11111111111111111
	  111111	1  111	    111111
	  111111	 1 111	    111111
	   1111111	  1111	   1111111
	  1 1111111	   111	  111111  1
	
			Welcome to
		GregTech:New Horizons
	The Minecraft Modpack Spend The MOST of Your Time
	上面的字符画是仿照这个Modpack的标画的
	我是蒟蒻 只过了A,B 
	C,D 暴力想不太出来
	Junior:348pts(CQ-J00288)
	Senior:224pts(CQ-S00234)
	Luogu UID:1612389
	Luogu:Yyz140116
	Atcoder:Yyz140116
	Codeforces:Yyz140116
	Bilibili:mlrpgpmmix
	thx.
*/
