#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200001];
bool f[200001];
void dfs(int num,int x){
	if(num==m){
		ans=max(x,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(num+1,x&a[i]);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(1,a[i]);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
