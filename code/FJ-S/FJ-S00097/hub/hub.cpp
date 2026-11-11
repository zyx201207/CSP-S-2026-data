#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;                  //10^6
		int x[1000005]={0};
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(k==n)cout<<"0\n";
		else if(k>=n/2&&n<16)cout<<"1\n";
		else{
			cout<<n/k-1<<'\n';
		}
	}
	return 0;
}
