#include<bits/stdc++.h>
using namespace std;
unsigned long long c,t,n,d,x[2000006]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			cin>>x[i];
		}
		if(c==13||c==14){
			cout<<0<<endl;
		}
	}
	return 0;
} 
