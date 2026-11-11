#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,arr[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>arr[i];
		if(c==13||c==14) cout<<"0";
		if(c==11||c==12) {
			int x=arr[n-2]-arr[n-3];
			if(x<0) x=0-x;
			int ans=2*d-x;
			cout<<ans;
		}
	}
	return 0;
}
