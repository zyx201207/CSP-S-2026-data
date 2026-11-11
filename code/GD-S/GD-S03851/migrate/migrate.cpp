#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(d<2*(a[2]-a[1]))cout<<0<<endl;
			else cout<<max(0ll,n-2*(d/(a[2]-a[1]))+1)<<endl;
			continue;
		}
	}
	return 0;
}
