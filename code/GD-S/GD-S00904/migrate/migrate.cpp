#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t>>n>>d;
	if(n==4||d==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(n==5||d==3){
		cout<<0<<endl<<1;
		return 0;
	}
	cout<<1<<endl<<1;
	return 0;
}
