#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int a[N],n,m,b[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;++i){
		int L=1,R=i-1,res=i;
		while(L<=R){
			int mid=(L+R)>>1;
			if(((i-mid+1)*a[i]-(sum[i]-sum[mid-1]))<=m){
				res=mid;R=mid-1;
			}else L=mid+1;
		}
		ans=max(ans,(i-res+1));
	}cout<<ans<<"\n";
	return 0;
}
