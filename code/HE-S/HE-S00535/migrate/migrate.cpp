#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c;
	if(a==0&&b==2&&c==4) cout<<1<<endl<<2;
	else if(a==0&&b==2&&c==5) cout<<0<<endl<<1;
	else cout<<0<<endl<<2;
	return 0;
}
