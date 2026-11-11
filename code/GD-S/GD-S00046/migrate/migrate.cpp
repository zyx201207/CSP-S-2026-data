#include<bits/stdc++.h>
using namespace std;
int n,d,ccf,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccf;
	cin>>t;
	for(int rp=0;rp<t;rp++){
		cin>>n>>d;
		long long m,a[2];
		for(int i=1;i<=n;i++){
			cin>>a[i%2];
		}
		m=a[1]-a[0];
		int b=n-2;
		if(d>=2*m)cout<<b<<endl;
		else cout<<"0"<<endl;;
	}
	return 0;
} 
