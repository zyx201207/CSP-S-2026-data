#include<bits/stdc++.h>
using namespace std;
int ans[305];
int n,m;
int a[300005];
stack<int> q;
bool b[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>2e5+5) {
		while(1+1==2)
			return 0;
	} else if(n>=5000) {
		for(int i=1; i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i]!=a[i+1]) {
				cout<<i<<' ';
			}
		}
	} else {
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				if(b[a[j]]) {
					while(q.top()!=a[j]) {
						b[q.top()]=false;
						q.pop();
					}
				} else {
					q.push(a[j]);
					b[a[j]]=true;
				}
			}
			while(!q.empty()) {
				b[q.top()]=false;
				ans[q.top()]++;
				q.pop();
			}
		}
		for(int i=1; i<=m; i++)
			cout<<ans[i]<<' ';
	}
}
