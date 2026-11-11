#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
bool check(int x){
	if(x<=1)return 1;
	int ans=1e18;
	for(int l=1;l+x-1<=n;l++){
		int r=l+x-1;
		ans=min(ans,(r-l)*a[r]-sum[r-1]+sum[l-1]);
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}else r=mid;
	}
	cout<<l;
	return 0;
} 
