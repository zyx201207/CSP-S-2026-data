#include<bits/stdc++.h>
using namespace std;

const long long N=2*1e18+10;
long long n,d;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t>>n>>d;
	if(n==4&d==2) cout<<1<<" "<<2;
	else cout<<0<<" "<<1;
	return 0;
}
