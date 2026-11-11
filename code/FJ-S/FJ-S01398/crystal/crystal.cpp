#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
int n,m,a[maxn],s[maxn];
signed main(){;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r+1)/2;
			__int128 x=a[i]*(i-mid);
			x-=(s[i]-s[mid]);
			if(x<=m) r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res);
	}
	cout<<ans;
	return 0;
}

