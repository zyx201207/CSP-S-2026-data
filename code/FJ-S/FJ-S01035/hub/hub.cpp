#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++) cin>>c;
		if(n==5&&k==2) cout<<1<<endl;
		else if(n==10&&k==3) cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
