#include<bits/stdc++.h>
using namespace std;
int a[6000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(d==2){
			cout<<n-3<<endl;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		
	}
	
	return 0;
}

 
