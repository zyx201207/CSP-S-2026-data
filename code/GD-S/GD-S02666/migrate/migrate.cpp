#include <bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int a[2000005];
int cnt_end,cnt;
int n,d;
int minn_short;
void dfs(int u,int v,int ans){
	if(u==v and ans==minn_short){
		cnt++;
		if(cnt==2){
			cnt_end++;
		}
		return;
	}
	if(u+d<=v){
		dfs(u+d,v,ans+1);
	}
	dfs(u+1,v,ans+1);
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>d;
		cnt_end=0,cnt=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				minn_short=((a[j]-a[i])/d)+((a[j]-a[i])-((a[j]-a[i])/d)*d)+1;
				dfs(a[i],a[j],0);
				maxn=max(maxn,cnt_end);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
