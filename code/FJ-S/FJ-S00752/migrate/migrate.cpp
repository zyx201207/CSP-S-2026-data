#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int o=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		o=x[2]-x[1];
		if(o==1){
			cout<<0<<endl;
		}else{
			cout<<(n-1)*(n-2)/2<<endl;
		}
	}
	return 0;
}
