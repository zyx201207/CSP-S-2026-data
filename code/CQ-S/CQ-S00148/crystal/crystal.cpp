#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,c[N],a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(c[i]-c[mid-1]+m>=a[i]*(i-mid+1)){
				sum=i-mid+1;r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
