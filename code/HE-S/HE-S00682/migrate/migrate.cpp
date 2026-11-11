#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,ans=0;
		long long d;
		cin>>n>>d;
		int sz[5010];
		for(int i=1;i<=n;i++){
			cin>>sz[i];
		}
		int js[5010];
		memset(js,0,n+1);
		for(int i=1;i<n;i++){
			if(sz[i]+d>=sz[i+1]&&sz[1]+d>=sz[i]&&sz[1]+d<sz[i+1]){
				js[i+1]++;
			}
		}
		for(int i=2;i<=n;i++){
			if(js[i]==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
