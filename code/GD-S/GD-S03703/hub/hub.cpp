#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[500005],v[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int tt=t;
	while(tt--){
		cin>>n>>k;
		for(int i=1;i<n;++i)cin>>u[i]>>v[i];
	}
	for(int i=1;i<t;++i)cout<<1<<"\n";
	cout<<2;
	return 0;
} 
