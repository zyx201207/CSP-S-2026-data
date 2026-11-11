#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans;
bool bk[200005];
void dfs(int dep,int sum){
	if(dep>k){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(bk[i]==0){
			bk[i]=1;
			dfs(dep+1,sum&a[i]);
			bk[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1073741823);
	cout<<ans;
}
