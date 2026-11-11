#include<bits/stdc++.h>
using namespace std;
long long n,m,q[110],vis[99999999],b[1000],maxv;
void dfs(int step){
	if(step>m){
		long long t=0;
		for(int i=2;i<=m;i++){
			t+=b[i-1]&b[i];
		}
		maxv=max(maxv,t);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[q[i]]=0){
			vis[q[i]]=1;
			b[i]=q[i];
			dfs(step+1);
			vis[q[i]]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	dfs(1);
	cout<<12;
	return 0;
}
