#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],dp[200010][2],ans,mi=1e18,mid;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	
	cout<<a[m];
	
	return 0;
}
