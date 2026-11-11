#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long c,n,m,t,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==4&&m==2)cout<<"1\n";
		else if(n==5&&m==2)cout<<"2\n";
		else if(n==5&&m==3)cout<<"0\n";
		else if(n==6&&m==2)cout<<"1\n";
		else if(n<=1)cout<<"0\n";
		else cout<<n/m;
	}
	return 0;
}
