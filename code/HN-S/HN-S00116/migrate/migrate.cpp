#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[200100];
int minn=1e9,cnt=0;
void dfs(int u,int e,int step){
	if(step>minn)return;
	if(u==e){
		if(step<minn){
			minn=step;
			cnt=1;
		}
		return;
	}
	int s=lower_bound(a+1,a+1+n,a[u]+d)-a;
	for(int i=min(n,s);i>=u;i++){
		if(a[i]-a[u]>d)continue;
		dfs(i,e,step+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=5e18,cnt=0;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}cout<<ans<<"\n";
	}
	
	return 0;
}

