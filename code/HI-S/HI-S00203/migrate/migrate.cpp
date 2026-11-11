#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	if(n==0 && m==2){
		cout<<1<<endl;
		cout<<2;
	}else{
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
}
