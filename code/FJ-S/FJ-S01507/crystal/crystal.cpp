//I AK CSP-S
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],b[N],ans;
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int tmp=x*a[i+x-1]-(b[i+x-1]-b[i-1]);
		if(tmp<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int minn=a[1];
	for(int i=1;i<=n;i++){
		a[i]-=minn;
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	//8 6 2 2 -5 -5 -7
	//2 4 0 7 0 2
	//2 4+2*2 4*2+2*3 7+4*3+2*4
	return 0;
} 
