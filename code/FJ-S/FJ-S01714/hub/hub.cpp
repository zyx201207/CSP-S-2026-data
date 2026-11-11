#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,k,T,a[N],res,ans,anss;
vector<int>v[N];
void dfs(int x,int fa,int t,int dis){
	if(x==t){
		res=min(res,dis);
		return ;
	}
	int i;
	for(i=0;i<(int)v[x].size();i++){
		int y=v[x][i];
		if(y==fa)continue;
		dfs(y,x,t,dis+1);
	}
}
void dfs1(int x,int m){
	if(m==k){
		int i,j;
		ans=0;
		for(i=1;i<=n;i++){
			res=1e8;
			if(a[i])continue;
			for(j=1;j<=n;j++){
				if(!a[j]||i==j)continue;
				dfs(i,0,j,0);
			}
			ans=max(ans,res);
		}
		anss=min(anss,ans);
		return ;
	}
	if(x>n)return ;
	for(x=x+1;x<=n;x++){
		a[x]=1;
		dfs1(x+1,m+1);
		a[x]=0;
	}
}
signed main(){
	int i,x,y;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		anss=1e8;
		dfs1(1,0);
		cout<<anss<<"\n";
	}
	return 0;
} 
