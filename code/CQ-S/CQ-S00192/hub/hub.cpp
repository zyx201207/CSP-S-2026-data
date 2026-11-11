#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int h[1000010],e[2000010],ne[2000010],idx;
int dep[1000010];//子树内的最深深度
int dp[1000010]; 
int X;
vector<int>vt[4010];
void add(int a,int b){
	idx++;
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void dfs(int u,int fa){
	dep[u]=0;
	int md=-1,hs;
	dp[u]=1;
	int md2=-1;
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(v==fa)continue;
		dfs(v,u);
		dep[u]=max(dep[u],dep[v]+1);
		if(dep[v]>md){
			md2=md;
			md=dep[v];
			hs=v;
		}
		else if(dep[v]>md2){
			md2=dep[v];
		}
		if(dep[v]+1<=X){

		}
		else{
			dp[u]+=dp[v];
		}
	}
	vt[u].clear();
	//md2=max(md2,0);
	if(md!=-1){//有儿子 
		swap(vt[u],vt[hs]);
		for(int j=0;j<(int)vt[u].size();j++){
			int rl=vt[u].size()-j;
			if(md2+1+1+rl<=X){
				
			}
			else{
				vt[u][j]=0x3f3f3f3f;
			}
		}
		vt[u].push_back(md2+1+1<=X?dp[hs]:0x3f3f3f3f);
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(v==fa||v==hs)continue;
			for(int j=0;j<(int)vt[v].size();j++){
				int rl=vt[v].size()-j;//距离v的真实距离
				if(rl+1+dep[u]<=X){
					vt[u][vt[u].size()-rl-1]=min(vt[u][vt[u].size()-rl-1],vt[v][j]);
				} 
			}
			vt[u][vt[u].size()-1]=min(vt[u][vt[u].size()-1],dep[u]+1<=X?dp[v]:(int)0x3f3f3f3f);
			vt[v].clear();
		}
	}
	//cout<<"dp:"<<u<<" "<<dp[u]<<endl;
}
bool check(int md){
	X=md;
	for(int u=1;u<=n;u++){
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(u<v){
				dfs(u,v);
				dfs(v,u);
				int mn1=0x3f3f3f3f;
				for(int j=0;j<(int)vt[u].size();j++){
					mn1=min(mn1,vt[u][j]);
				}
				mn1=min(mn1,dp[u]);
				int mn2=0x3f3f3f3f;
				for(int j=0;j<(int)vt[v].size();j++){
					mn2=min(mn2,vt[v][j]);
				}
				mn2=min(mn2,dp[v]);
				if(mn1+mn2<=k){
					//cout<<"uv:"<<u<<" "<<v<<" "<<X<<endl;
					return 1;
				}
			}
		}
	}
	return 0;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)h[i]=0;
	idx=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(n<=4000){
		int l=0,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<"\n";
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,tt;
	cin>>c>>tt;
	while(tt--)solve();
	return 0;
}
