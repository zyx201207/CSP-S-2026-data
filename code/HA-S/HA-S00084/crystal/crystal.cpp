#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],ans=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
	ll i,j;
	for(i=1,j=1;i<=n&&j<=n;i++){
		while((i-j+1)*a[i]-s[i]+s[j-1]>m) j++;
		ans=max(i-j+1,ans);
	}
	cout<<ans;
	return 0;
}
