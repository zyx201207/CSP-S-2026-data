#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N],ans;
int sum[N];
bool check(int l,int r){
	return a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    int l,r,mid,pans;
    for(int i = 1;i<=n;++i){
		l=1,r=i-1,pans=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i))pans=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pans+1);
	}
	cout<<ans;
    return 0;
}
