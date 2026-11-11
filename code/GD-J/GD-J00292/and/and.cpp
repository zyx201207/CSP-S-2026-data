#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
priority_queue<int>q;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=1;i<=m-1;i++) {
		q.pop();
	}
	cout<<q.top();
	return 0;
}
