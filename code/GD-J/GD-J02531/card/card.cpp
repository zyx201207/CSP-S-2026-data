#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],last[300005],vis[300005],put[500005],l;
void dfs(long long k,long long p){
	if(p==0)return;
	put[++l]=a[k];
	if(vis[a[k]]){
		for(int i=1;i<=k-vis[a[k]];i++)
		l--;
	}
	vis[a[k]]=l;
	dfs(k+1,p-1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		memset(put,0,sizeof(put));
		memset(vis,0,sizeof(vis));
		l=0;
		dfs(i,n-i+1);
		for(int i=1;i<=l;i++)last[put[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<last[i]<<" ";
	return 0;
}

