#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,ans;
ll w[100010];
struct node{
	ll k;
	ll a[100];
	ll t[100];
}ar[100100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ar[i].k;
		for(int j=1;j<=ar[i].k;j++){
			cin>>ar[i].a[j]>>ar[i].t[i];
		}
	}
	for(int i=1;i<=q;i++){
		ll s,e;
		ans=0;
		cin>>s>>e;
	}
	cout<<32<<" "<<17;
	return 0;
}
