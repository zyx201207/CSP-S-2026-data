#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int sum[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int Ans=1;
	for(int i=1;i<=n;i++){
		int maxn=a[i];
		int l=1,r=i-1,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*maxn-(sum[i]-sum[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		Ans=max(Ans,i-ans+1);
	}
	cout<<Ans<<"\n";
	return 0;
}
