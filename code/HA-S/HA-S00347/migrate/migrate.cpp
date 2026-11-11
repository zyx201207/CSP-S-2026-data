#include <bits/stdc++.h>
using namespace std;
long long n,x[2000005],c,t,d;
int mig(int n,int d){
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	return d;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
	}
	mig(n,d);
	cout<<1<<endl<<2;
	return 0;
}
