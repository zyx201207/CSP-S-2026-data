#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],n,m,pref[N];
bool check(int x){
	int res=1e18;
	for(int i=1;i<=n-x+1;i++)
		res=min(res,a[i+x-1]*x - (pref[i+x-1]-pref[i-1]));
	return res<=m;
}
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}
