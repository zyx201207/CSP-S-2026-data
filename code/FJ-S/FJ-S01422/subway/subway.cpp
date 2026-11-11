#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k,x,y,A,T;
vector<int>a[505],t[505];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++)cin>>A>>T,a[i].push_back(A),t[i].push_back(T);
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<"\n";
	}
	return 0;
}
