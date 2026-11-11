#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],n,l,r,ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	while(l<r){
		int len=min(a[l],a[r]);
		if (c[l]!=c[r]){
			ans+=len;
		}
		a[l]-=len;
		a[r]-=len;
		if (a[l]==0)l++;
		if (a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
