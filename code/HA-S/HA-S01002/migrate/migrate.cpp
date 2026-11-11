#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		long long a=x[2]-x[1];
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if((j-i)*a>d&&(j-i)*a<2*d){
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

