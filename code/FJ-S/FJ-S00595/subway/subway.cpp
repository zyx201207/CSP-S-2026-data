#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=5*1e5+25;
int c,n,m,d,q;
int w[INF];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(q--){
		cout<<-(c+n+m-d+q)<<endl;
	}
	return 0;
}
