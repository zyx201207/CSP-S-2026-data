//GZ-S00326 遵义市南白中学 陈梓睿
#include <bits/stdc++.h>
#define ll long long
#define M 2000060
using namespace std;
ll c,t,n,d,a[M],ans,mn,ci;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		for(int i = 1;i<=n;i++) cin>>a[i];
		ll gc = a[2]-a[1];
		if(gc>=d){
			cout<<"0\n";
		}else{
			ll sum = (d/gc)*2;
			ll k = a[1]+(sum-1)*gc;
			if(a[n]<k) cout<<"0\n";
			else {
				cout<<((a[n]-k)/gc+1)<<"\n";
			}
		}
	}
	return 0;
}


