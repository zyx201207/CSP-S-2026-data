#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[500010],ans;
int check(int x){
	int l=1,r=x,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if((x-mid+1)*a[x]-s[x]+s[mid-1]<=m)r=mid-1,res=mid;
		else l=mid+1;
	}
	return x-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)ans=max(check(i),ans);
	cout<<ans;
	return 0;
}
