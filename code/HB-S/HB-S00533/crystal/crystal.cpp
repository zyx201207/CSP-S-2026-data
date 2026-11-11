#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005];
void dfs(long long sum,int l,int k){
	for(int i=k-1;i>=1;i--){
		if(a[i]==a[k]){
			sum++;
			ans=max(ans,sum);
		}else if(a[k]-a[i]<=l){
			sum++;
			l=l+a[i]-a[k];
			ans=max(ans,sum);
		}else{
			return ;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		dfs(1,m,i);
	}cout<<ans;
	return 0;
}
