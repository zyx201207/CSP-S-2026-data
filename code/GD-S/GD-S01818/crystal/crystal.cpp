#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n,m,a[maxn],sum[maxn],ans;
int query(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-query(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/
