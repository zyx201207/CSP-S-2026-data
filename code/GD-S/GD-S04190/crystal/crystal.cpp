#include<bits/stdc++.h>
#define int long long
#define fo(i,n) for(int i = 1;i<=n;i++) 
#define foi(i,n,m) for(int i = n;i<=m;i++) 
using namespace std;
const int N = 1e6 + 10;
int n,m,a[N],qian[N];
bool check(int x,int y){
//	cout<<x<<" "<<y<<" "<<a[y]<<" "<<(y-x+1)<<" "<<-qian[y]+qian[x-1]<<" "<<((a[y]*(y-x+1)-qian[y]+qian[x-1])<=m)<<endl;
	return ((a[y]*(y-x+1)-qian[y]+qian[x-1])<=m);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fo(i,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	fo(i,n){
		qian[i] = qian[i-1]+a[i];
	}
	int ans = 1;
	fo(i,n){
		int l = 1,r = i;
//		cout<<l<<" "<<r<<endl;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid,i)){
				r = mid-1;
			} 
			else l = mid+1;
		}
		ans = max(ans,i-r);
//		cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}
