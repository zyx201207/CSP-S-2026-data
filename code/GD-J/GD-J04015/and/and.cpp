#include <bits/stdc++.h>
using namespace std;
using ll= long long;
ll n,m,a[200100],b[200100],cnt,t;
bool c[65];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt=0,t=a[i];
		while(t){
			cnt+=t%2;
			t/=2;
		}
		b[i]=cnt;
	}
	sort(a+1,a+1+n,greater<ll>());
	t=a[1];
	for(ll i=1;i<=m;i++){
		t=t&a[i];
	}
	cout<<t;
	return 0;
}
