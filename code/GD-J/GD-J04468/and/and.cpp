#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string ss;
const ll mmm=2e5+200;
ll n,m;
ll a[mmm];
ll cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}
