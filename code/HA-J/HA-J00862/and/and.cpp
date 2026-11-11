#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
int n,m;
ll ans;
priority_queue<int>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	ans=q.top();
	for(int i=2;i<=m;i++){
		q.pop();
		ans&=q.top();
	}
	cout<<ans;
	return 0;
}
