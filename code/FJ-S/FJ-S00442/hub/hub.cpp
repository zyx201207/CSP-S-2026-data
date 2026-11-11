#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int dep[1000005];
bool f[100005],dfn[100005];
int n,k;
int ans;
void dfs(int x,int fa){
	dfn[x]=1;
	for(int i=0;i<v[x].size();i++){
		int to=v[x][i];
		if(to==fa||!f[to])continue;
		dfs(to,x);
	}
}
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1; 
	for(int i=0;i<v[x].size();i++){
		int to=v[x][i];
		if(to==fa)continue;
		dfs1(to,x);
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++)dfn[i]=0;
	for(int i=1;i<=n;i++){
		if(f[i]&&!dfn[i]){
			cnt++;
			dfs(i,0);
		}
	}
	return cnt<=2;
}
void cz(){
	int ma=0;
	for(int i=1;i<=n;i++){
		dfs1(i,0);
		int mi=0x3f3f3f3f;
		for(int j=1;j<=n;j++)if(f[j])mi=min(mi,dep[j]);
		ma=max(ma,mi);
	}
	ans=min(ans,ma);
}
void xz(int x,int num){
	if(x==n){
		if(num==k&&check()){
			cz();
		}
		return ;
	}
	x++;
	f[x]=0;
	xz(x,num);
	f[x]=1;
	xz(x,num+1);
	f[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=0x3f3f3f3f;
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(k==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i]=f[j]=1;
					if(i!=j&&check())cz();
					f[i]=f[j]=0;
				}
			}
			cout<<ans-1<<'\n';
			continue;
		}
		xz(0,0);
		cout<<ans-1<<'\n';
	}
	return 0;
}

