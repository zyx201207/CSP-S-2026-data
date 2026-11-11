#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans; 
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i,res=1;
	//	cout<<i<<"\n";
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*mid-(s[i]-s[i-mid])<=m)
				res=mid,l=mid+1;
			else
				r=mid-1;
		//	cout<<l<<" "<<r<<" "<<mid<<" "<<a[i]*mid-s[i]+s[i-mid]<<"\n";
		}
		ans=max(ans,res);
		//cout<<res<<"\n\n";
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
// 15：26 T1 大样例通过。 
