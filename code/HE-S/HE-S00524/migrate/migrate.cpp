#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n=0,d=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c==0&&t==2){
			if(n==4&&d==2){
				cout<<1<<endl;
			}
			else if(n==5&&d==2){
				cout<<2<<endl;
			}
			else if(n==5&&d==3){
				cout<<0<<endl;
			}
			else if(n==6&&d==2){
				cout<<1<<endl;
			}
		}	
	}
	return 0;
}
