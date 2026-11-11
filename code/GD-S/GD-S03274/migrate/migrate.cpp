#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[2]-x[1]>=d){
			cout<<0<<'\n';
			continue;
		}
		cout<<abs(n-d)/min(n,d)<<'\n';
	}
	return 0;
}
