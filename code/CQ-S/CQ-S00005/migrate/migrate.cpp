#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,d,ans=1e9,cnt=0,a[5001];
bool vis[5001];
void dfs(int now,int t,int sum){
	if(now==t){
		if(sum<ans) ans=sum,cnt=1;
		else if(sum==ans) cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(abs(a[now]-a[i])<=d&&!vis[i]){
			vis[i]=1;
			dfs(i,t,sum+1);
			vis[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=1e9,cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int st=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				dfs(j,i,0);
				if(cnt==2) st++;
				ans=1e9,cnt=0;
				memset(vis,0,sizeof(vis));
			}
		}
		cout<<st<<"\n";
	}
	
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
