#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
vector<int>e[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		int u,v;
		for(int i=1;i<n;i++)cin>>u>>v;
		int ans=floor(sqrt(n))-floor(sqrt(k));
		if(ans<1)cout<<1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
