#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],flag[N],maxn;
void dfs(long long x,long long ans){
	if(ans<maxn) return;
	if(x==m) {
		maxn=max(maxn,ans);
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			dfs(x+1,(ans&a[i]));
			flag[i]=0;
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
	dfs(0,a[i]);
	}
	cout<<maxn;
	return 0;
}
