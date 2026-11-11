#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define maxn ((int)(5e5)+10)
#define maxm ((int)(1e18)+10)
//------------------------------
// ahh the "1e18"&"1e12"
//------------------------------
// Ten years' OI empties in a competition,
// If no long long  you can see your ancesters(?)
//------------------------------
int n,m;
int a[maxn],sum[maxn];
bool check(int x){
	int val=0x3f3f3f3f3f3f3f3f;
	for(int l=1,r=l+x-1; r<=n; l++,r++){
		val=min(a[r]*x-sum[r]+sum[l-1],val);
		if(val<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
//I get it!!!!! 100pts
