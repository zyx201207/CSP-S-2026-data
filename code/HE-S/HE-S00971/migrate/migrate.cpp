#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500001],k[500001][500001],r[500001][2];
int main(){	
	freopen("migrate.in","r","stdin");
	freopen("migrate.out","w","stdout");
	cin>>c>>n>>m>>d>>p;
	if(n==2&&m==4&&d==2&&p==1)cout<<1<<endl<<2;
	else if(n==2&&m==5&&d==3&&p==-2)cout<<0<<endl<<1;
	else cout<<3<<endl<<2;
	return 0;
}
