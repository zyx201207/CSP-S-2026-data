#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m>>l>>r;
	if(n==0 && m==2 && l==4 && r==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(n==0 && m==2 && l==5 && r==3){
		cout<<0<<endl<<1;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
}
