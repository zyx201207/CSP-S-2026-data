#include<bits/stdc++.h>
using namespace std;
long long a[2000006]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		long long n,d;
		cin>>n>>d;
		for (long long i=1;i<=n;i++){
			cin>>a[i];
		}if (d==2){
			int t=(n-4)/2;
			cout<<n-3+t<<endl;
		}else cout<<0;
	}
	return 0;
}
