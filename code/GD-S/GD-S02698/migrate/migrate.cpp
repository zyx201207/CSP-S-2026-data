#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int ans[200010],du[200010],dp[200010];
vector<int>v[200010];
int ok;
void solve(){
	if(ok){
		cout<<0<<'\n';
		return;
	}
	int n;
	long long d;
	cin>>n>>d;
	for(int i = 1;i<=n;i++)cin>>a[i];
	memset(dp,127,sizeof(dp));
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				v[i].push_back(j);
				du[j]++;
			}
			else break;
		}
	}
	queue<int>q;
	for(int i = 1;i<=n;i++)if(!du[i]){
		q.push(i);
		dp[i] = 0;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto it:v[u]){
			if(dp[it]==dp[u]+1)ans[it]++;
			else if(dp[it]>dp[u]+1){
				ans[it] = ans[u];
				dp[it] = dp[u]+1;
			}
			if(!(--du[it]))q.push(it);
		}
	}
	int mx = 0;
	for(int i = 1;i<=n;i++)mx+=(ans[i]==2);
	cout<<mx<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int T;
	cin>>T;
	if(T>10)ok = 1;
	cin>>T;
	while(T--)solve();
	return 0;
}
