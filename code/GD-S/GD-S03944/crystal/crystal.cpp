#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500007],s[500007];
int check(int len,int l){
	int r=l+len-1;
	int sum=(len-1)*a[r]-s[r-1]+s[l-1];
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int l=1;l<=n;l++){
		int lo=1,hi=n-l+2,mid,mx=0;
		while(lo<hi){
			mid=(lo+hi)/2;
			if(check(mid,l)<=m){
				lo=mid+1;
				mx=mid;
			}
			else hi=mid-1;
		}
//		cout<<l<<" "<<mx<<" "<<check(mx,l)<<"\n";
		ans=max(ans,mx);
	}
	cout<<ans;
	return 0;
}
