#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200009],sum[200009],ans,cnt;
void dfs(ll cnt,ll sh){
	if(cnt==m){
		ans=max(ans,sum[m]);
		return;
	}
	if(cnt==0){
		for(ll i=1;i<=n-(m-cnt-1)+1;i++){
			cnt++;
			sum[cnt]=a[i];
			dfs(cnt,i);
			sum[cnt]=0;
			cnt--;
		}
	}else{
		for(ll i=sh+1;i<=n-(m-cnt)+1;i++){
			cnt++;
			sum[cnt]=(sum[cnt-1]&a[i]);
			dfs(cnt,i);
			sum[cnt]=0;
			cnt--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
