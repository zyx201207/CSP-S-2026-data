#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>u>>v;
		cout<<(((n+1)/2)-k)/4+1<<"\n";
	}
}
