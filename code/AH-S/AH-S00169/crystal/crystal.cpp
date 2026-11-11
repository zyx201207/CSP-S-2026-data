#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN],ans=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int cur=1e9;
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			int val=a[i]*(i-mid)-s[i-1]+s[mid-1];
			if(val<=m) r=mid-1,cur=mid;
			else l=mid+1;
 		}
 		ans=max(ans,i-cur+1);
	}
	cout<<ans<<endl;
	return 0;
}
