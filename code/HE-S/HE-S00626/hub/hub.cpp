#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005],minn;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		if(n==k) cout<<"0\n";
		else if(2*k>=n) cout<<"1\n";
		else if(3*k>=n) cout<<"2\n";
		else cout<<"3\n";
}
	return 0;
} 
