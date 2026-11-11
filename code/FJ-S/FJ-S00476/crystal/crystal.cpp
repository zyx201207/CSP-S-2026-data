#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005];
int l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(r<n){
		int t=a[r+1]-a[r];
		while(m<(r-l+1)*t&&l<=r) m+=a[r]-a[l++];
		if(l>r) r++;
		else r++,m-=t*(r-l);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
