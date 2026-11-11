#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5+7;
int n,m,ans;
int a[N],s[N];
int getlen(int x){
	int l=1,r=x,ans=0;
	while(l<=r){
		int mid=l+r>>1,len=x-mid+1;
		if(a[x]*len-(s[x]-s[mid-1])<=m){
			ans=len;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,getlen(i));
	cout << ans;
	return 0;
}
