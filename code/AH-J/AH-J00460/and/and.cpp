#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[1000000],m;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	
	return 0;
}
