#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,j=i;
		while(l<=r){
			int mid=l+r>>1;
			ll len=i-mid+1;
			if(len*a[i]-(s[i]-s[mid-1])<=m) r=mid-1,j=mid;
			else l=mid+1;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
