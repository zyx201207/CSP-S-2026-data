#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,cnt=0,mx;
bool vis[200005];
void dfs(int k,int nnum,int nmax){
	if(k==m){
		cnt=max(cnt,nnum);
		cout<<nnum<<' ';
		return;
	}
	for(int i=1;i<=n;++i){
		if(a[i]<nmax && !vis[i]){
			dfs(k+1,(nnum&a[i]),a[i]+1);
			vis[i]=1;
		}
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx<<'\n';
		return 0;
	}
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(1,a[i],a[i]); 
	}
	cout<<cnt<<'\n';
	return 0;
}
