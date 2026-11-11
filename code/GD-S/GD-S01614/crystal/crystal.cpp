#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500001],m,sum[500010],ans;
int find114(int i){
	int l=0,r=i+1;
	while(l+1<r){
		int mid=l+r>>1;
		if((i-mid)*a[i]-sum[i-1]+sum[mid-1]<=m) r=mid;
		else l=mid;
	}
	return r;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int g=find114(i);
		ans=max(ans,(i-g+1));	
	}
	cout<<ans;
} 
