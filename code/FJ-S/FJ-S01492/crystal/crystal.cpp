#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int inf=0x3f3f3f3f,N=500005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll s=0; int ans=1;
	for(int l=1,r=1;r<=n;r++){
		if(r>1) s+=(r-l)*(a[r]-a[r-1]);
		while(s>m) s-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}