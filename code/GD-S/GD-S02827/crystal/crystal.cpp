#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500001];
ll b[500001];
ll mop=0;
ll kl=0;
ll ans=0;
queue<ll> q;
ll qwe=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);

	for(int i=1; i<=n; i++) {

		mop+=kl*(a[i]-a[i-1]);
		q.push(a[i]);
		kl++;
		while(!q.empty()&&mop>m) {
			qwe=q.front();
			mop-=a[i]-a[qwe];
			q.pop();
			kl--;
		}
		ans=max(kl,ans);
		//cout<<kl<<" "<<mop<<" "<<endl;
	}
	cout<<ans;
	return 0;
}
