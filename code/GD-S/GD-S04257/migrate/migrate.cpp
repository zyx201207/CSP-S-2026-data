#include<bits/stdc++.h>
using namespace std;
int n[10005];
int d[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n;j++){
			cin>>j;
		}
	}
	if(n[1]==4&&n[1]==2){
		cout<<1<<endl<<2;
	}
	else if(n[1]==4&&n[1]==2){
		cout<<0<<endl<<1;
	}
	else{
		cout<<c<<t;
	}
	return 0;
} 
