#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d<2*(a[2]-a[1]))cout<<0<<endl;
		else cout<<(a[n]-a[1]-d)/(a[2]-a[1])<<endl;
	}
	return 0;
}
