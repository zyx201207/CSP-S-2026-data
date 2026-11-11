#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int c,t,n,k,u[N],v[N];
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>u[i]>>v[i];
	cout<<abs(u[0]-v[0])<<endl;;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
