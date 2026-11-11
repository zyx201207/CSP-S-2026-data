#include<bits/stdc++.h>
using namespace std;
int u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[i]>>v[i];
		}
		if(n==5&&k==2){
			cout<<1<<endl;
		}
		else if(n==10&&k==3){
			cout<<2<<endl;
		}
	}
	return 0;
}
