#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m,ans;
int a[maxn];
stack<int> p,q;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		while(!q.empty()){
			int x=q.top();
			q.pop();
			if(x>>i&1){
				cnt++;
			}
			p.push(x);
		}
		while(!p.empty()){
			if(cnt<m||(p.top()>>i&1)){
				q.push(p.top());
			}
			p.pop();
		}
	}
	ans=(1<<30)-1;
	while(m--){
		ans&=q.top();
		q.pop();
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
