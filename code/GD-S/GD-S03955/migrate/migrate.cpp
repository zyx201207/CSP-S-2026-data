#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5005],ans,cnt,minn;
void dfs(int l,int r,long long u,long long sum){
	if(u==r){
		if(sum<minn){
			cnt=1,minn=sum;
		}else if(sum==minn)cnt++;
		return;
	}
	if(sum>minn)return;
	for(int i=r;i>u;i--){
		if(x[i]-x[u]<=d)
			dfs(l,r,i,sum+1);
	}
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=998244353,cnt=0;
				dfs(i,j,i,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
