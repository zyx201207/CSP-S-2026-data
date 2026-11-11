#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500+9,M=5e5+9;
int w[N];
vector<int> a[M];
vector<int> t[M];
void solved(){
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x,t1; cin>>x>>t1;
			a[i].push_back(x);
			t[i].push_back(t1);
		}
	}
	while(q--){
		int ans=0;
		int x,y; cin>>x>>y;
		ans+=w[x]+w[y];
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	int t; cin>>t; while(t--)
	solved();
	return 0;
}
