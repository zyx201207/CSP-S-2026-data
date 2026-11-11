#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans=-1,m;
bool f[200005];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int sum,int dep){
	if(sum<ans) return ;
	if(dep==m){
		ans=sum;
		return ;
	}for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			dfs((sum&a[i]),dep+1);
			f[i]=false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			dfs(a[i],1);
			f[i]=false;
		}
	}
	cout<<ans;
	return 0;
}
