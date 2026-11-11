#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
#define mkp make_pair
const int N=5e5+5;
int n,m,a[N],maxn,sum[N];
//Oct31==Dec25? 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)sum[i]=sum[i-1]+a[i];
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,ans = i;
		while(l<=r){
			int mid=(l+r)>>1;
			int x = sum[i]-sum[mid-1];
			if((i-mid+1)*a[i]-x<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}maxn=max(maxn,i-ans+1);
	}cout << maxn;
	return 0;
}
/*
键盘手感还行，有一点回弹。
不是如果只有一颗水晶呢？参与合并吗
应该是可以的，没强调。如果挂了那我真服了 
*/
