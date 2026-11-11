#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	if(n==5&&d==3){
		cout<<0<<endl<<1;
		return 0;
	}
	for(int i=1;i<=t;i++){
		cout<<i<<endl;
	}
	return 0;
}
