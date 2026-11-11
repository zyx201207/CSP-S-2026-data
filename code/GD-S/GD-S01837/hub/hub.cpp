#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int>e[N];
int op,T;
int d[N],maxd=0,maxn=0,pre=0;
int ye=0;
void dfs(int x,int fa){
	d[x]=d[fa]+1;
	if(d[x]>maxd){
		pre=maxd;
		maxd=d[x];
		maxn=1;
	}else if(d[x]==maxd){
		maxn++;
		pre=maxd;
	}else if(d[x]>pre)pre=maxd;
	int cnt=0;
	for(int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if(fa==v)continue;
		dfs(v,x);
		cnt++;
	}
	if(cnt==0)ye++;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>op>>T;
	while(T--){
		maxn=0;
		maxd=0;
		pre=0;
		ye=0;
		memset(d,0,sizeof(d));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(k==n-1){
			cout<<"1\n";
			continue;
		}
		d[0]=-1;
		dfs(1,0);
		if(k>=n-ye){
			cout<<"1\n";
			continue;
		}
		if(k==2){
			cout<<(maxd+pre)/2<<"\n";
			continue;
		}
		cout<<(maxd-k/maxn)/2<<"\n";
	}
	return 0;
} 
/*
Oct31==Dec25?

*/
