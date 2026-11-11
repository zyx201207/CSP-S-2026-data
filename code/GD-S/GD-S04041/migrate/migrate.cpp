#include<bits/stdc++.h>
using namespace std;
long long t,tt,n,m,a[200000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tt>>t;
	while(t){
		cin>>n>>m;
		long long nn=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		nn=a[2]-a[1];
		if(m<=nn){
			cout<<"0"<<endl;
			t--;
			memset(a,0,sizeof(a));
			continue;
		}
		if(m>=2*nn&&m<3*nn){
			cout<<n-3<<endl;
			t--;
			memset(a,0,sizeof(a));
			continue;
		}
		memset(a,0,sizeof(a));
		t--;
	}
	return 0;
} 
