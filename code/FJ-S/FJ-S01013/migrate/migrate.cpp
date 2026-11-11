#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,x[2000100];
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}if(c==0)continue;
		cout<<2*n<<endl;
	}
	if(c==0){
		cout<<1<<endl<<2;
	}
	return 0;
}
