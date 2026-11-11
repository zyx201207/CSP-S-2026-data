#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=1,now;
int f(int x){
	int l=1;
	for(int i=x+1;i<=n;i++){
		now+=l*(a[i]-a[i-1]);
		if(now>m)return l;
		l++;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=max(ans,f(i));
	}
	cout<<ans;
	return 0;
}
