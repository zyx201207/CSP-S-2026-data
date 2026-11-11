#include<bits/stdc++.h>
using namespace std;
int n,u[1000006],v[1000006],c,t,k;
long long ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
		ans=(n+1)/2;
//		cout<<ans<<" ";
		ans=(ans-k+2)/2;
		ans=(ans+1)/2;
		cout<<ans<<"\n";
	}
	return 0;
}
