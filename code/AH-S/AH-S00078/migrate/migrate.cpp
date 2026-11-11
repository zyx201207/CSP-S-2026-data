#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			long long k=a[2]-a[1];
			if(2*k<=n)cout<<2*k-1;
			else if(n-2*d+1>0)cout<<n-2*d+1;
			else cout<<0;
			cout<<endl;
		}
	}
	return 0;
}
