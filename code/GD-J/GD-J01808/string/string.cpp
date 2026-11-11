#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l,r;
int ans;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		int mn=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=mn;
		a[l]-=mn,a[r]-=mn;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
