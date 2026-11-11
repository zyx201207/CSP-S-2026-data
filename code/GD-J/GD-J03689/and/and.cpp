#include <bits/stdc++.h>
using namespace std;
long long ans=0;
bool f[(1<<20)+10]={false};
int a[200010];
void dfs(int idx,long long sum,int n,int m){
	if(idx==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[a[i]]){
			f[a[i]]=true;
			dfs(idx+1,(sum&a[i]),n,m);
			f[a[i]]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	//f[a[1]]=true;
	dfs(0,(long long)(2>>31)-1,n,m);
	cout<<ans;
	return 0;
}
