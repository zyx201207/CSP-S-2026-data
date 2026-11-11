#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll c,m,n,d,q,w[N],k,x,y,t[505][N],ans;
vector<ll> a[505];
struct zh{
	int ss;
	vector<ll> id;
};
zh sub[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) t[i][j]=-1;
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			sub[a1].ss++;
			sub[a1].id.push_back(i);
			t[a1][i]=t1;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
	}
	cout<<ans;
	return 0;
}
