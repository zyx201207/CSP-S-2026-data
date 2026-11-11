#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define sc second
const int N=5e5+7;
int n,l,r,ans=0;
ll m,cnt=0;
ll a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m; l=r=n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(;r>=1;--r){
		while(a[r]-a[l-1]+cnt<=m && l-1>=1) l--,cnt+=a[r]-a[l];
		ans=max(ans,r-l+1);
		cnt-=(r-l)*(a[r]-a[r-1]);
	}cout<<ans<<"\n";
	return 0;
} 
