#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
bool b[200005];
int ans=0;
void dfs(int p,int c){
	
	if(p>=m){
		ans=max(ans,c);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		dfs(p+1,c&a[i]);
		b[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		dfs(1,a[i]);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}

