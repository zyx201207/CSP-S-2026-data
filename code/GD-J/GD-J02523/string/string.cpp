#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];char s[200005];
struct da{
	int l,r;
}d[200005];
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n,lg=0;
	cin>>n;
	d[0].r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		d[i].l=d[i-1].r+1;
		d[i].r=d[i-1].r+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[n-i+1])continue;
		else ans+=abs(a[i]-a[n-i+1]);
	}
	cout<<ans;
	return 0;
}
