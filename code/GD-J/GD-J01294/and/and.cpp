#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
int a[200010];

void dfs(int xb,long long z,int sd){
	if(sd==m){
		ans=max(ans,z);
		return ;
	}
	for(int i=xb+1;i<=n;i++){
		dfs(i,z&a[i],sd+1);
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	
	cout<<ans;
	return 0;
}
