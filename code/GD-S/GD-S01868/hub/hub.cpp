#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long c,n,k,t,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u[i]>>v[i];
		cout<<n/k-1<<"\n"; 
	}
	return 0;
}
