#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int id,val;
};
const int N=505;
int w[N];
int c,n,m,d,q,ans,x,r;
vector<node> g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>g[i].id>>g[i].val;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			mn_val=min(mn_val,g[i].val);
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+mn_val
	}
	return 0;
}
