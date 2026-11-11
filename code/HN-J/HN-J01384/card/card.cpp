#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int dp[500005];
bool vis[500005];
void ans(int x){
	memset(vis,0,sizeof(vis));
	deque<int>q;
	for (int i=x;i<=n;i++){
		if (!vis[a[i]]){
			q.push_back(a[i]);
			vis[a[i]]=true;
		}else{
			while(!q.empty() && q.back()!=a[i]){
				vis[q.back()]=false;
				q.pop_back();
			}
		}
	}
	while(!q.empty()){
		dp[q.back()]++;
		q.pop_back();
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		ans(i);
	}
	for (int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
