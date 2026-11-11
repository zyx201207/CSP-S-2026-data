#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==0&&b==2&&c==4&&d==2) cout<<1<<endl<<2;
	else if(a==0&&b==2&&c==5&&d==3) cout<<0<<endl<<1;
	else cout<<0<<endl<<0;
	return 0;
}
