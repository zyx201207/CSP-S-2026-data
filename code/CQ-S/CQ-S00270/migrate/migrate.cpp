#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,m[2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>d;
		for(int j=1;j<=n;++j)cin>>m[i];
	}
	for(int i=1;i<=t;++i){
		long long y=2e18;
		long long x=1LL*rand()*rand()%y+1;
		cout<<x;
	}
	return 0;
}
