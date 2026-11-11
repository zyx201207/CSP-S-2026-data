#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int MAXN=2e6+10;
int a[MAXN];
int dis[MAXN];
int cnt[MAXN];
void dfs(int u,int fa){
	for(int i=u+1;i<=n;i++){
		if((a[i]-a[u])<d){
			dis[i]=min(dis[i],dis[u]+1);
			dfs(i,u);
		}
	}
}

void dfs2(int u,int fa,int dis){
	if(dis==dis[u])cnt[u]++;
	for(int i=u+1;i<=n;i++){
		if((a[i]-a[u])<d){
			dfs(i,u,dis+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ANS=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			memset(dis,0x7f7f7f7f,sizeof(dis));
			dis[i]=0;
			dfs(i,0);
			dfs2(i,0,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ANS++;
			}
		}
		cout<<ANS<<endl;
	}
	return 0;
}

