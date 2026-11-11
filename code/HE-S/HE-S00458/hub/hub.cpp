#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,v[1000010],u[1000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>v[j]>>u[j];
		}
		cout<<c*t*k;
	}
	return 0;
}
