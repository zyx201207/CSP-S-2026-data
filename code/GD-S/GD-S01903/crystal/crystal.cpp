#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int lb=1,ub=i;
		while(lb<=ub){
			int mid=lb+ub>>1;
			if(mid*a[i]-(sum[i]-sum[i-mid])<=m)lb=mid+1;
			else ub=mid-1;
		}
		ans=max(ans,lb-1);
	}
	cout<<ans<<endl;
}
