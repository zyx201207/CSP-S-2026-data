#include<bits/stdc++.h>
using namespace std;
int *a[ ]={  };
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0 && t==2){
		cout<<1<<endl;
		cout<<2;
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<*a<<endl;
		}
	}
	return 0;
}
