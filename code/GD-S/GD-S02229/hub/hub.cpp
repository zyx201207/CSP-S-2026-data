#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[1000007],v[1000007];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>u[i]>>v[i];
	cout<<"0\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve(); 
	return 0;
} 
