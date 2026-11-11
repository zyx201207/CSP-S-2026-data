#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

