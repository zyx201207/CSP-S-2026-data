#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s,f[2005][2005];
int dfs(int p,int t){
	if(f[p][t]!=-1)return f[p][t];
	if(t==1)return a[p];
	int ans=0;
	for(int i=p+1;i<=n;i++){
		ans=max(ans,a[p]&dfs(i,t-1));
	}if(f[p][t]==-1)f[p][t]=ans;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			f[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		s=max(s,dfs(i,m));
	}cout<<s;
	return 0;
}

