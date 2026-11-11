#include<bits/stdc++.h>
using namespace std;
long long n;
struct nodd{
	string s;
	long long k;
}a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].k>>a[i].s;
	if(n==1) {
		cout<<0;
		return 0;
	}
	long long ans=0,j=n;
	bool f=0;
	for(int i=1;i<=n;i++){
		if(f) break;
		while(a[i].k){
			if(i==j) {
				f=1;
				break;
			}
			if(!a[j].k) j-=1;
			if(i==j) {
				f=1;
				break;
			}
			if(a[i].s==a[j].s){
				long long g=min(a[j].k,a[i].k);
				a[j].k-=g;
				a[i].k-=g;
			}else {
				long long g=min(a[j].k,a[i].k);
				ans+=g;
				a[j].k-=g;
				a[i].k-=g;
			}
		}
	}
	cout<<ans;
	return 0;
}
