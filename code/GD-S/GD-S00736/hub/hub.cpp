#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int u[1000005];
		int v[1000005];
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<i;
	}
	return 0;
}
