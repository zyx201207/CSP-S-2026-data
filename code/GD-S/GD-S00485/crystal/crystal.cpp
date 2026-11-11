#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],d[N],pre[N],cnt,res,l=1,r;
bool check(int x){
	int sum=0;
	for(int i=2;i<=x;i++) sum+=d[i]*(i-1);
	if(sum<=m) return 1;
	for(int i=x+1;i<=n;i++){
		sum-=pre[i-1]-pre[i-x+1];
		sum-=d[i-x+1]*(i-x);
		sum+=d[i]*(i-1);
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+d[i];
//		cout<<pre[i]<<' ';
	}
//	for(int i=n-1;i>=1;i--) sub[i]=sub[i+1]+d[i];
	r=n;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	if(check(r)) cout<<r;
	else cout<<l;
	return 0;
}
/*315275

7 3
6 8 8 10 10 10 11
*/
