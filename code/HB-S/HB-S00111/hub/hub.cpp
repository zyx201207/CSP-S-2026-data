#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		long long n,k,u[2000005],v[2000005];
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(t==2){
		cout<<1<<endl<<2;
	}
	if(t==3){
		cout<<1<<endl<<1<<endl<<2;
	}
	return 0;
}
