#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool check(int x){
	int res=0,ans=1e18;
	for(int i=1;i<=x;i++){
		res+=a[x]-a[i];
	}
//	cout<<1<<" "<<x<<" "<<res<<"\n"; 
	ans=min(ans,res);
	int l=1,r=x;
	while(r+1<=n){
		res+=(r-l)*(a[r+1]-a[r]);
		res-=a[r]-a[l];
//		cout<<l+1<<" "<<r+1<<" "<<res<<"\n";
		ans=min(ans,res);
		l++;r++;
	}
//	cout<<ans<<"\n";
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	cout<<check(315275)<<"\n";
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	} 
	cout<<ans<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
