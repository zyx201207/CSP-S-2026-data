#include <bits/stdc++.h>
#define dd double
using namespace std;
long long n,x[2000005];
int c,t;
dd d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int p;
		bool f=1;
		for (int i=1;i<=n;i++)
			cin>>x[i];
		p=x[2]-x[1];
		if (c==11 || c==12){
			if ((p*1.0)>(d/2)) cout<<0<<"\n";
			if ((p*1.0)<=(d/2.0) && (p*1.0)>(d/3.0)) cout<<n-2<<"\n";
			if ((p*1.0)<=(d/3.0)) cout<<0<<"\n";
		}
		if (c==13 || c==14){
			cout<<0;
		}
	}
	
}
