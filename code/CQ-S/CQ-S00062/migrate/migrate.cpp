#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000005],ans=1e9;
void dfs(int n,int d,int x,int sum){
	if(x==n){
		ans=min(ans,sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>d)break;
		dfs(n,d,i,sum+1);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		ans=1e9;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(n,d,1,0);
		sum+=ans;
		cout<<sum<<"\n";
	}
	return 0;
}

