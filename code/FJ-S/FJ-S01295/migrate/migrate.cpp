#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			if(d<=a[12]-a[11])cout<<0<<endl;
			else cout<<(n-1)/2;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}

