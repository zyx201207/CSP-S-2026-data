#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=0x3f3f3f3f3f3f3f3f;
int n,m,a[500001],p,q,mcost,ans;
int s[500001];
int calc(int q,int i){
	return (i-q)*a[i]-(s[i-1]-s[q-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(calc(mid,i)>m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
}
