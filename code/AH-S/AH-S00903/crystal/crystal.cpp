#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,lg[500005],a[25][500005],sum[500005];
int get(int l,int r){
	int tmp=lg[r-l+1];
	return max(a[tmp][l],a[tmp][r-(1ll<<tmp)+1]);
}
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++) if(get(i,i+mid-1)*mid<=m+sum[i+mid-1]-sum[i-1]) return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) cin>>a[0][i];
	sort(a[0]+1,a[0]+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[0][i];
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i+(1ll<<j)-1<=n;i++){
			a[j][i]=max(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}

