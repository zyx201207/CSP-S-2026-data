#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],s[500001],ans;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		int l=1,r=i;
		while(l<=r){
			int d=(l+r)/2;
			if(s[i]-s[d-1]-(d-1)*(a[i]-a[d-1])>m)l=d+1;
			else r=d-1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
} 
