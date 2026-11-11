# include <bits/stdc++.h>
# define N 500010
# define int long long 
using namespace std;
int n,m,a[N],sum[N],anss=1;
bool check(int mid,int id) {
    if(a[id+1]*(id-mid+1)-(sum[id]-sum[mid-1])<=m) return true;
    return false;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	  sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) {
	  int l=1,r=i-1,ans=1;
	  while(l<=r) {
	    int mid=(l+r)>>1;
	    if(check(mid,i-1)) ans=i-mid+1,r=mid-1;
	    else l=mid+1;
	  }
	  anss=max(anss,ans);
	}
	cout<<anss;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7

