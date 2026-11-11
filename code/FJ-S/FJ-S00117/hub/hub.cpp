#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000005]={0},v[2000005]={0};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		n=n/4/4;
		cout<<n;
	}
	return 0;
}
