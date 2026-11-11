#include <bits/stdc++.h>
using namespace std;
//int a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			int yachiyo;
			cin>>yachiyo;
		}
		long long ans=(long long)n*(n-2);
		ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
}

