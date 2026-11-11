#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=205;
int a[205];
int c,t;
int n,k;
int f[maxn];
int flo[maxn][maxn];
vector<vector<int> > aa(1145);
int ans;
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void check(){
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			int fa=find(i);
			for(int j=0;j<aa[i].size();j++){
				int to=aa[i][j];
				
				if(a[to]) f[to]=fa;
			}
		}
	}
	
	int c[114];
	memset(c,0,sizeof(c));
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]&&c[find(i)]==0) c[find(i)]=1,num++;
	}
	//cout<<num<<' ';
	if(num>2){
		return;
	}
	
	int mi=0;
	for(int i=1;i<=n;i++){
		int mx=114514;
		if(a[i]) mx=0;
		for(int j=1;j<=n;j++){
			if(a[j]){
				mx=min(mx,flo[i][j]);
				}
		}
		mi=max(mi,mx);
	}
	ans=min(ans,mi);
}

void dfs(int now,int num){
	if(now==n){
		a[n]=0;
		if(num==k)check();
		a[n]=1;
		if(num+1==k) check();
		return;
	}
	a[now]=0;
	dfs(now+1,num);
	if(num+1>k) return;
	a[now]=1;
	dfs(now+1,num+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=114514;
		cin>>n>>k;
		aa.clear();
		memset(flo,0x3f,sizeof(flo));
		
		for(int i=1;i<n;i++){
			flo[i][i]=0;
			int u,v;
			cin>>u>>v;
			aa[u].push_back(v);
			aa[v].push_back(u);
			flo[u][v]=1;
			flo[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					flo[i][j]=min(flo[i][j],flo[i][k]+flo[k][j]);
				}
			}
		}
	
		
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	return 0;
}

 
