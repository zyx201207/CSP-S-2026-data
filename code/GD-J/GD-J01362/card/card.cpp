#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//#define int long long
const int N=5e5+10;
const int M=3e5+10;
int n,m,ans[M];
int a[N],vis[M];
vector<int> nxt[M];
int dfs(int pos,int p){
	int cnt=nxt[p].size();
	for(int i=0;i<nxt[p].size();i++){
		int v=nxt[p][i]-1;
		if(!vis[a[v]]&&v!=0&&v==nxt[a[v]][0]){
			vis[a[v]]=1;
			cnt+=dfs(v,a[v]);
		}
	}
	ans[p]=cnt;
	return cnt;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		nxt[a[i]].push_back(i);
	}
	dfs(n,a[n]);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}
/*
4 3
1 2 1 3
*/
