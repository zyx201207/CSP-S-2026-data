#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+7,N=5e2+7;
int t;
int n,d;
int a[N];
int sum,mn;
void dfs(int x,int u,int v,int ta){
	if(x==v){
		if(mn==ta)
			sum++;
		if(ta<mn)
			mn=ta,sum=1;
		return ;
	}
	for(int i=x+1;i<=v;i++){
		if(a[i]-a[x]>d)
			break;
		dfs(i,u,v,ta+1);
	}
	return ;
}
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=0,mn=1e18;
			dfs(i,i,j,0);
			if(sum==2)
				ans++/*,cout<<i<<" "<<j<<"\n"*/;
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c>>t;
	while(t--)
		solve();
	
	return 0;
}
/*
 0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
*/
