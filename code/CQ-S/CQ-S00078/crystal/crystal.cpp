#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid+1;
		}
//		cout<<i<<" "<<l<<"\n";
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9
*/
