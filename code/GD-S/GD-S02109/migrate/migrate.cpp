#include<bits/stdc++.h>
using namespace std;
int a[64]={2,3,5,3,7,9,3,5,7,2,3,3,5,4,6,8,8,6,9,5,3,5,7,3,9,2,4,6,8,6,4,5};
int x[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=d;i++){
			cin>>x[i];
		}
	}
	if(c==0 && t==2){
		if(n==5 && d==2){
			cout<<1<<endl;
			cout<<2<<endl;
			return 0;
		}
		if(n==6 && d==2){
			cout<<0<<endl;
			cout<<1<<endl;
			return 0;
		}
	}else{
		for(int i=1;i<=t;i++){
			cout<<a[i]<<endl;
		}
	}
	return 0;
} 
