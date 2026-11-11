#include<bits/stdc++.h>
#define int long long
int a[500005],n,m;
bool vis[3005][200005];
void cal(int x){
	for(int i=x;i<=n;i++){
		if(!vis[x][a[i]]){
			vis[x][a[i]]=true;
		}
		else{
			for(int r=i;r>=x;r--){
				if(a[r]==a[i])break;
				vis[x][a[r]]=false; 
			}
		}
	}
	return;
}
signed main(){
//	std::freopen("card.in","r",stdin);
//	std::freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
//	memset(lst,-1,sizeof lst);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)cal(i);
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i])++ans;
		}
		printf("%lld ",ans);
	}
	return 0;
}
