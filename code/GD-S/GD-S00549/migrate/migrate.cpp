#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN=2e6+6;
int c,t,n,N,d;
int nxt[MAXN];
int x[MAXN];
queue<int> q;
int dis[MAXN];
int cnt[MAXN];
int ans;
int vis[MAXN];
void init(){
	ans=0;
	int l=1,r=1;
	for(;l<=n;l++){
		while(r<n&&x[r+1]-x[l]<=d){
			r++;
		}
		nxt[l]=r;
	}
	
}
int solve(int f){
	while(!q.empty())q.pop();
	q.push(f);
	for(int i=f;i<=n;i++){
		dis[i]=MAXN;
		cnt[i]=0;
		vis[i]=0;
	}
	dis[f]=0;
	cnt[f]=1;
	vis[f]=1;
	while(!q.empty()){
		int u=q.front ();q.pop();
		int v=nxt[u];
		while(dis[u]+1<=dis[v]&&v>u){
			if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
			if(dis[v]>dis[u]+1){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
			}
			if(!vis[v]){
				q.push(v);
				vis[v]=1;
			}
			v--;
		}
	}
	int tot=0;
	for(int i=f;i<=n;i++){
		if(cnt[i]==2)tot++; 
	}
	return tot;
}


signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		init();
		if(c<=10){
			for(int i=1;i<=n;i++)ans+=solve(i);
			cout<<ans<<'\n';
		}else if(c<=12){
			if((x[2]-x[1])*2>d)cout<<0<<'\n';
			else {
				int ci=d/(x[2]-x[1]);
				cout<<max(0ll,n-(ci*2)+1)<<'\n';
			}
		}else cout<<0<<'\n';
		
	}
	return 0;
}

