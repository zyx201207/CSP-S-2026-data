#include<bits/stdc++.h>
using namespace std;
long long x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long s=0;
	for(int i=1;i<=t;i++){
		int n;
		long long d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			
		} 
		s=x[n]-x[n-1];
		long long l=2*d/s-1;
		cout<<n-l<<endl;
	}
	return 0;
}
