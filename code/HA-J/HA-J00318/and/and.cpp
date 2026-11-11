#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
priority_queue<ll> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		q.push(a);
	}
	ans=q.top();
	q.pop();
	for(int i=2;i<=m;i++){
		ll c=q.top();
		q.pop();
		ans=ans&c;
	}
	cout<<ans;
	return 0;
}
