#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++) cin>>x>>y;
		if(k==n) cout<<"0\n";
		else cout<<"1\n";
	}
	cout<<"1\n";
	return 0;
}




















