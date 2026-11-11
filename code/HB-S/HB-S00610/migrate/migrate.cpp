#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
		int h=d/(a[2]-a[1]);
		int ans=n-h*2+1;
		if(ans>0)cout<<ans<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}
