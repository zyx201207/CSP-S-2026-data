#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ap[500005];
int dp[500005];
int ap_w[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>q;
	stack<int>p;
	for(int i=n;i>=1;i--){
		ap[a[i]]++;
		if(ap[a[i]]==2){
			while(!q.empty()&&q.top()!=a[i]){
				ap[q.top()]--;
				q.pop();
			}
			ap[a[i]]--;
		}
		else q.push(a[i]);
		while(!q.empty()){
			dp[q.top()]++;
			//cout<<q.top()<<" "<<i<<endl;
			p.push(q.top());
			q.pop();
		}
		while(!p.empty()){
			q.push(p.top());
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
