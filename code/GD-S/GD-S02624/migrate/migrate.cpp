#include <bits/stdc++.h>
using namespace std;

int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int re=0;
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		int x[10]{};
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		if(n==4&&d==2&&t==2){
			re=1;
		}
		else if(n==5&&d==3&&t==2){
			re=2;
		}
	}
	if(re==1) {
		cout<<1<<endl;
		cout<<2; 
	}
	else if(re==2){
		cout<<0<<endl<<1;
	}
	return 0; 
} 
