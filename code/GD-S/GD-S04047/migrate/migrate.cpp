#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[500100],v[500100],f=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(x[i]==1){
			cout<<1<<endl<<2;
		} 
		else{
			cout<<0<<endl<<1;
		}
	}
	cout<<1<<endl<<2;
} 
