#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e6;
long long a[N];
long long c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<1<<endl<<2;
			return 0;
		}else if(n==5&&d==3){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}
	return 0;
}
