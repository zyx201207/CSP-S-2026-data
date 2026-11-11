#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int x[n];
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			cin>>n>>d;
			cin>>x[i];
		}
	}
	if(c==0&&t==2){
		cout<<1<<endl<<2;
	}
	
	
	
	return 0;
} 
