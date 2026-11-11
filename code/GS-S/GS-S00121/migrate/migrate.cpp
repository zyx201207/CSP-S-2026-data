#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)    cin>>a[i];
		if(a[3]-a[1]<=d&&a[2]-a[1]>d)	cout<<n-3<<'\n';
		else    cout<<0<<'\n';
	}
	return 0;
}

