#include<bits/stdc++.h>
using namespace std;
int c,t,k;
int ans;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int len=x[2]-x[1];
		if(d>=(n-1)*len){
			cout<<n<<'\n';
			continue;
		}
		for(int i=1;i<=n+5;i++){
			if(d<len*i){
				k=i-1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(j-i<=k*len&&j-i>(k-1)*len) ans++;
			}
		}
		cout<<ans<<'\n';
	}
return 0;
}
