#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int s[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		int need=a[i]*x-(s[i]-s[i-x]);
		if(need<=m)	return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))	ans=mid,l=mid+1;
		else	r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
} 
