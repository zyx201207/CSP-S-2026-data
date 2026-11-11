#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=n;
	for(int i=n;i>=1;i--){
		l=min(l,i);
		while(l>1&&(i-l+2)*a[i]-(s[i]-s[l-2])<=m)l--;
		mx=max(mx,i-l+1LL);
	}
	cout<<mx;
	return 0;
}
