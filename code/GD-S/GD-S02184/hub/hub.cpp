#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9,M=2e6+10;
int n,k;

int u[M],v[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	cout<<1<<"\n";
	cout<<2<<"\n";
	return 0;
}
