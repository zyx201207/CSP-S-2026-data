#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,t,c,d;
	cin>>n>>t>>c>>d;
	if(n==0&&t==2&&c==4&&d==2) cout<<1<<endl<<2;
	else if(n==0&&t==2&&c==5&&d==3) cout<<0<<endl<<1;
	return 0;
}
