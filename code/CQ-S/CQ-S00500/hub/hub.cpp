#include <bits/stdc++.h>
using namespace std;
int C,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++) cin>>u>>v;
		cout<<(n-k)/3<<'\n';
	}
	return 0;
}
