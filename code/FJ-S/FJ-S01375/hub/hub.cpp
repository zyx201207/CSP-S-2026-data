#include<bits/stdc++.h>
using namespace std;
long long t,c,n,k,v[1000005],u[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>k;
		for(long long j=1;j<=n-1;j++){
			cin>>u[i]>>v[i];
		} 
	    cout<<n-1<<"\n"<<n;
    }
	return 0;
}
