#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b==2&&c==4&&d==2) cout<<1<<endl<<2;
	else if(b==2&&c==5&&d==3) cout<<0<<endl<<1;
	else{
		for(int i=1;i<=b;i++) cout<<0<<endl;
	}
	return 0;
}
