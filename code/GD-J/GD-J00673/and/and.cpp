#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
ll dp[maxn],a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n>=2e3){
		bool flag=0;
		for (int i=1;i<=n;i++) if (a[i]!=i-1) flag=1;
		if (flag){
			priority_queue<int> q;
			for (int i=1;i<=n;i++) q.push(a[i]);
			ll ans=q.top();
			q.pop();
			for (int i=2;i<=m;i++){
				ans&=q.top();
				q.pop();
			}
			cout<<ans;
			return 0;
		}
		else{
			priority_queue<int> q;
			for (int i=1;i<=n;i<<=1)q.push(i-1);
			ll ans=q.top();
			q.pop();
			for (int i=2;i<=m;i++){
				ans&=q.top();	
				q.pop();
			}
			cout<<ans;
			return 0;
		}
	}
	dp[0]=(1<<30)-1;
	for (int i=1;i<=n;i++){
		for (int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
