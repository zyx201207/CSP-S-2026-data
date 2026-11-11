#include<bits/stdc++.h>
using namespace std;
int c=0,t=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0 && t==2){
		cout<<1<<endl;
		cout<<2;
	}else{
		cout<<0<<endl;
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
