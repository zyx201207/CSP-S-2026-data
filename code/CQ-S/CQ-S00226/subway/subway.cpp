#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int c,n,m,d,q;

int w[N];

struct node{
	int v,t;
};

vector<node> e[N],zt[N];

int ans=INT_MAX;

bool vis[N][500];

bool vis1[N];

void dfs(int now,int flag,int d,int x){
	cout<<now<<" "<<flag<<" "<<d<<" "<<x<<endl;
	if(now==flag){
		int wz;
		for(int i=0;i<zt[now].size();i++) if(zt[now][i].v==x){
			wz=i;
			break;
		}
		if(x!=0) d+=zt[flag][wz].t;
//		cout<<zt[flag][wz].t<<endl;
		d+=w[flag];
		ans=min(ans,d);
		return;
	}
	if(x==0){
		for(int i=0;i<zt[now].size();i++){
			if(vis[now][zt[now][i].v]) continue;
//			cout<<zt[now][i].v<<" ";
			vis[now][zt[now][i].v]=true;
			vis1[now]=true;
			dfs(now,flag,d+zt[now][i].t,zt[now][i].v);
//			cout<<endl;
			vis1[now]=false;
			vis[now][zt[now][i].v]=false;
		}
	}
	else if(x!=0){
		for(int i=0;i<e[now].size();i++){
			if(vis[e[now][i].v][x]||x!=e[now][i].t) continue;
			vis[e[now][i].v][x]=true;
			dfs(e[now][i].v,flag,d,x);
			vis[e[now][i].v][x]=false;
		}
		if(vis1[now]) return;
		vis1[now]=true;
		int wz;
		for(int i=0;i<zt[now].size();i++) if(zt[now][i].v==x){
			wz=i;
			break;
		}
		dfs(now,flag,d+zt[now][wz].t,0);
		vis1[wz]=false;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(last!=-1){
				e[last].push_back({a,i});
				e[a].push_back({last,i});
			}
			last=a;
			zt[a].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dfs(x,y,w[x],0);
		cout<<ans<<'\n';
		ans=INT_MAX;
	}
	return 0;
}

/*
26/10/31 16:09
神了,睡会
26/10/31 16:26
睡醒了 
26/10/31 17:26
ccfnb,能拿199.9999...pts吗
*/
