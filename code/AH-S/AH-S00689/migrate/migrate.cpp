#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		long long n,d;
		cin>>n>>d;
		long long x[n+5];
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		long long k=x[2]-x[1];
		//cout<<k<<" ";
		if(d<=k){
			cout<<"0"<<endl;
			continue;
		}
		d/=k;
		//cout<<d<<" ";
		if(n<2*d-1){
			cout<<"0"<<endl;
			continue;
		}
		else
			cout<<n-2*d+1<<endl;
	}
	return 0;
}
