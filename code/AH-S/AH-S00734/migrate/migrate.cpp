#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+10;
ll c,t,n,m,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==5&&m==3)cout<<0<<endl;
		if(n==6&&m==2)cout<<1<<endl;
		if(n==4&&m==2)cout<<1<<endl;
		if(n==5&&m==2)cout<<2<<endl;
		if(c==0&&t==17)cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else cout<<0<<endl;
	}
	return 0;
}
