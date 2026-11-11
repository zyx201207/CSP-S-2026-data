#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000010;
int ID;
int n,k;
vector<int>g[N];
int popcount(int x){
	int cnt=0;
	while(x)x&=x-1,cnt++;
	return cnt;
}
bool b[N],vis[N];
void findltk(int x){
	vis[x]=1;
	for(int i=0;i<(int)g[x].size();i++){
		int y=g[x][i];
		if(!vis[y]&&b[y])findltk(y);
	}
}
int dis[N];
int mn[N];
void dfs(int x,int fa){
	for(int i=0;i<(int)g[x].size();i++){
		int y=g[x][i];
		if(y==fa)continue;
		dis[y]=dis[x]+1;
		dfs(y,x);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(n==k){
		cout<<"0\n";
		return;
	}
	if(k+1==n){
		cout<<"1\n";
		return;
	}
	if(ID<=3){
		int ans=1e9;
		for(int s=1;s<(1<<n);s++)if(popcount(s)==k){
			for(int i=1;i<=n;i++)b[i]=(s>>(i-1))&1;
			int cnt=0;
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int i=1;i<=n;i++)if(b[i]&&!vis[i]){
				cnt++;
				if(cnt>2)break;
				findltk(i);
			}
			if(cnt>2)continue;
			for(int i=1;i<=n;i++)mn[i]=1e9;
			for(int i=1;i<=n;i++)if(b[i]){
				dis[i]=0;
				dfs(i,-1);
				for(int j=1;j<=n;j++)mn[j]=min(mn[j],dis[j]);
			}
			int mx=0;
			for(int i=1;i<=n;i++)mx=max(mx,mn[i]);
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
		return;
	}
	int m=n/2;
	int mxb1=(m+1)/2,mxb2=m/2;
	int f1=(k+1)/2,f2=k/2;
	cout<<max((mxb1-f1+1)/2+1,(mxb2-f2+1)/2+1)<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>ID>>_;
	while(_--)solve();
    return 0;
}

