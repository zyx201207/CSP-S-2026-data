#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		long long n,d,a[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==2){
			cout<<(n/2+n%2-1)%2<<endl;
		}
	}
	return 0;
}
