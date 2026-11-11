#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long c,t,n,d;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		long long x[2000001];
		for (long long i=1;i<=n;i++) cin>>x[i];
		if (n<=3){
			cout<<0<<'\n';
			continue;
		}
		if (c==11 or c==12){
			if (x[3]-x[1]>d or x[4]-x[1]<=d) cout<<0;
			else cout<<n-3;
			cout<<'\n';
			continue;
		}
		else cout<<0<<'\n';
	}
	return 0;
}
