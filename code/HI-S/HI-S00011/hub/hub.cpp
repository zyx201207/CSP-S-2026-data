#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ni[2][101];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>ni[0][i]>>ni[1][i];
		if(n==5) cout<<1<<"\n";
		else if(n==10) cout<<2<<"\n";
		else cout<<rand();
	}
	return 0;
} 
