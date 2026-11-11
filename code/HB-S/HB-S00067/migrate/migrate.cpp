#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,x[2000005],ways;
void dfs(int now,int e,int sum){
	if(sum==0&&now!=e)return;
	if(sum==0&&now==e){
		ways++;
		return;
	}
	for(int i=now;i<=e;i++){
		if(x[i]-x[now]>d)break;
		dfs(i,e,sum-1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;
	cin>>_>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ways=0;
				dfs(i,j,ceil(1.0*(j-i)/d));
				if(ways==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
