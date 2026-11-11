#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans,ansn;
int n,m;
long long maxx=-1;
void dfs(int p){
	if(p==m){
		maxx=max(maxx,ans);
		ans=ansn;
		return ;
	}
	for(int i=1;i<=m;i++){
		ans=ansn&a[i];
		p++;
		dfs(p);
		p=0;
		ansn=a[1];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ansn=a[1];
	dfs(1);
	cout<<maxx;
	return 0;
}
