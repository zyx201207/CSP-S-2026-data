#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}
