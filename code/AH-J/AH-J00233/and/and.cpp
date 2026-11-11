#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200003];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll k;
	for(ll i=1;i<=m;i++){
		if(i==1)k=a[i];
		else k&=a[i];
	}
	cout<<k;
	return 0;
}
