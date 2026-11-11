#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll c,n,m,d,q;
ll w[N];
ll a[N],t[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int i=1;i<=x;i++){
			cin>>a[i]>>t[i];
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<abs(x-y)*w[x]<<'\n';
	}
	return 0;
}
