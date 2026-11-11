#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000001],ans,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]-a[j]==m*2-1){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
