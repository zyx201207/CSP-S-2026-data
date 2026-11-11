#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int c,t;
int x[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int k=rand();
		cout<<k<<'\n';
	}
	return 0;
}
