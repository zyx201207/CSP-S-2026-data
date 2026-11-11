#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int lst=0,ans=0;
		bool ok=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1){
				continue;
			}
			if(i==2){
				lst=x[i]-x[i-1];
				continue;
			}
			if(x[i]-x[i-1]!=lst){
				ok=0;
			}
		}
		if(ok==1){
			if(n%d!=d-1){
				cout<<0<<'\n';
			}
			else{
				cout<<n/d<<'\n';
			}
			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(x[i]+d<x[i-1]){
					break;
				}
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


