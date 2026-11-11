#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u;v<=n;v++){
				if(x[v]-x[u]<=d){
					continue;
				}
				int sum=0;
				for(int k=u+1;k<v;k++){
					if(x[v]-x[k]<=d&&x[k]-x[u]<=d){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
