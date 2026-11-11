#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,m;
ll a[200005],maxn;
void dfs(ll ans,ll t,ll sum){
	if(sum==m){
		maxn=max(maxn,ans);
	}
	if(ans==0) return ; 
	if(ans>maxn) maxn=ans;
	if(a[t]==0||a[t]==1){
		dfs(ans,t+1,sum);
	}else{
		dfs((ans&a[t]),t+1,sum+1);
		dfs(ans,t+1,sum);
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<maxn;
	fclose(stdin);
    fclose(stdout);
    return 0;
}
 
