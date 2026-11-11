#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],ans;

void dfs(long long x,long long y,long long sum){
	if(y==m){
		ans=max(ans,sum);
		return ;
	}
	if(x==n){
		return ;
	}
	if(y==0){
		dfs(x+1,y+1,a[x+1]);
	}else{
		dfs(x+1,y+1,sum&a[x+1]);
	}
	dfs(x+1,y,sum);
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
