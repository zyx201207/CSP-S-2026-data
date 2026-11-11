#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
#define ll long long
int n;
ll m;
ll a[MAXN],s[MAXN];
bool check(int x){
	for (ll i=x;i<=n;i++){
		if (x*a[i]-(s[i]-s[i-x])<=m) return true;
	}
	return false;
}
bool cmp(ll x,ll y){return x<y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
//RP++;
// 26-10-31 14:39 100
