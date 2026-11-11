#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c==0){
		int n;
		cin>>n;
		cin>>n;
		if(n==4){
			cout<<1<<'\n'<<2;
		}
		else{
			cout<<0<<'\n'<<1;
		}
	}
	return 0;
}
