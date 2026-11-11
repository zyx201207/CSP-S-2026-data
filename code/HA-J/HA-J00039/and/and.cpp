#include<bits/stdc++.h>
using namespace std;
long long res;
long long arr[200005];
long long n,m;
void dfs(long long k,long long step,long long ans){
	if(step==m){
		res=max(res,ans);
		return;
	}
	if(k==n+1||(n-step<m-1)){
		return;
	}
	dfs(k+1,step,ans);
	dfs(k+1,step+1,(ans&arr[k]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1,0,(1<<31)-1);
	cout<<res;
	return 0;
}
