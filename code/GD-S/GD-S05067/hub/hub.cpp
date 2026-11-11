#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e8+5;
ll c,t,n,k,ans=0;
ll u[N],v[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
