#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],sum[N],f[N],la[300010];
vector<int> g[N];
void dfs(int u){
	sum[a[u]]++;
	if(g[u].empty()) return;
	int v=g[u][0];
	dfs(v);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;++i){
			if(a[i]!=a[i+1]) cout<<i<<' ';
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
		    g[j].clear();
		}
		memset(f,0,sizeof(f));
		memset(la,0,sizeof(la));
		g[0].push_back(i);
		la[a[i]]=i;
		for(int j=i+1;j<=n;++j){
			if(!la[a[j]]){
				g[j-1].push_back(j);
				f[j]=j-1;
				la[a[j]]=j;
			}
			else{
				for(int l=la[a[j]]+1;l<j;++l){
					la[a[l]]=0;
				}
				g[f[la[a[j]]]].clear();
				g[f[la[a[j]]]].push_back(j);
				f[j]=f[la[a[j]]];
				la[a[j]]=j;
			}
		}
		dfs(0);
	}
	for(int i=1;i<=m;++i){
		cout<<sum[i]<<' ';
	}
	cout<<endl;
	return 0;
}

