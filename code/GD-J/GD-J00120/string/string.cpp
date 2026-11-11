#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],l,r,ans;
char ch[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	l=1,r=n;
	while(l<r){
		if(ch[l]!=ch[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]) a[r]-=a[l],l++;
		else if(a[l]>a[r]) a[l]-=a[r],r--;
		else l++,r--;
	}
	cout<<ans;
	return 0;
}
