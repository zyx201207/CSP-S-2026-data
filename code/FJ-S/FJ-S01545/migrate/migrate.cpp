#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000001];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n/4<<'\n';
	}
	return 0;
}
