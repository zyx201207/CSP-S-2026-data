#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char s[200005];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int l=1,r=n,l_now=a[l],r_now=a[r];
	while(l<r){
		if(s[l]!=s[r]) ans+=min(l_now,r_now);
		if(l_now<r_now) r_now-=l_now,l++,l_now=a[l];
		else if(l_now>r_now) l_now-=r_now,r--,r_now=a[r];
		else l++,r--,l_now=a[l],r_now=a[r];
	}
	cout<<ans;
	return 0;
}
