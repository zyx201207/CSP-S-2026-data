#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,u[2000010],v[2000010],ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=-1;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
			ans=min(ans,abs(u[i]-v[i]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
