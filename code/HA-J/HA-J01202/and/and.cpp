#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
