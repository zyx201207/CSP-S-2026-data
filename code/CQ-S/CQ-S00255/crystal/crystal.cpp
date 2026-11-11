#include<bits/stdc++.h>
#define int lint
using namespace std;
using lint=long long;
using llint=__int128;
using ldouble=long double;
const int MAX_N=5e5+10,INF=1e18;
int a[MAX_N],pre_sum[MAX_N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre_sum[i]=pre_sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(pre_sum[i]-pre_sum[mid-1]+m>=a[i]*(i-mid+1)){
				r=mid-1;
				res=max(res,i-mid+1);
			}
			else l=mid+1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
