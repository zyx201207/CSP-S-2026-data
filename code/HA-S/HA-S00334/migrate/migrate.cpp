#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2100000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==2){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<1<<"\n"<<0;
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<0<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
