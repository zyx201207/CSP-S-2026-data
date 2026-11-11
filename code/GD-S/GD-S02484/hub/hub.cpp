#include<bits/stdc++.h>
using namespace std;
void solve(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
	}
	cout<<n-k<<"\n";
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
