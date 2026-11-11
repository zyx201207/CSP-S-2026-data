#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		long long g[1000000005]={0};
		for(int j=0;j<n;j++){
			cin>>g[j]; 
		}
		if(n%2==1){
			cout<<2;
		}else{
			cout<<1;
		}
	}
	
	return 0;
}
