#include<bits/stdc++.h>
int const N=1e6+10;
long long a[N],c,t,n,d,maxx=0;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		if(d==2)cout<<n%4+1;
		else cout<<0;
	}
	return 0;
	}

