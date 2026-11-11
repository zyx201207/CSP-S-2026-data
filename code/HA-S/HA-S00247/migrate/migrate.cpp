#include<bits/stdc++.h>
using namespace std;
int x[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int k=x[2]-x[1];
		if(d<2*k){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
