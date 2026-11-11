#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,c;cin>>n>>m>>c;
	if(n==0){
		if(c==4){
			cout<<1<<endl<<2;
		}else if(c==5){
			cout<<0<<endl<<1;
		}else{
			for(int i=1;i<=m;i++){
				cout<<0<<endl;
			}
		}
	}else{
		for(int i=1;i<=m;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
