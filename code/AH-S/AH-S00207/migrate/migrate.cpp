#include<bits/stdc++.h>
using namespace std;
long long dsbc,T,n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>dsbc>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long sb=d/(a[2]-a[1]);
		n=n-d-d+1;
		if(n%2==1) cout<<((n+1)/2)*((n+1)/2)<<"\n";
		else cout<<(n/2)*(n/2+1)<<"\n";
	}
	return 0;
}




















