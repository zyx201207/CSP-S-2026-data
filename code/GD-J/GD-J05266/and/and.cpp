#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=0,m=0,ans;
ll a[200010];
//& °´Î»Óë 
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];		
	}	
	sort(a+1,a+1+n,cmp);
	ans = a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
