#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5;
ll a[N+10];
bool f[N+10];

int n,m;
ll ans=0;


void dfs(int sum, int cur, ll num){
	if(cur==n+1){
//		for(int i=1;i<cur;i++)cout<<f[i];
		if(sum==m){
//			cout<<"*"<<num<<"\n";
			ans=max(ans, num);
			return; 
		}
//		cout<<"\n";
		return;
	}
	if(sum==m){
		ans=max(ans, num);
		return; 
	}
	
//	0
	dfs(sum, cur+1, num);
//	1
	f[cur]=1;
	if(sum==0){
		dfs(sum+1, cur+1, a[cur]);
	}else{
		dfs(sum+1, cur+1, (num & a[cur]));
	}
	f[cur]=0;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	dfs(0,1,0);
	
	
	cout<<ans;
	return 0;
}

//5 3 31 3 1 15 7
