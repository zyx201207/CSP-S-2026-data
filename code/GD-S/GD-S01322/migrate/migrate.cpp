#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000002],n,d,ans;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=0; i<n; i++) cin>>x[i];
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				if((x[j]-x[i])%d==d-1 && (x[j]-x[i])/d>=1) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
