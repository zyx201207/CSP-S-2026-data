#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],mn,mx,ans=1,c;
bool f=1;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mx=min(mn,a[i]),mx=max(mx,a[i]);
	sort(a+1,a+1+n);c=a[2]-a[1];
	for(int i=3;i<=n&&f;i++)if(a[i]-a[i-1]!=c)f=0;
	if(f){
		int s=0;
		for(int i=n-1;i>=1&&s+(a[n]-a[i])<=m;i--)s+=(a[n]-a[i]),ans++;
		cout<<ans;
		return 0;
	}
	for(int i=mn;i<=mx;i++){
		int x=lower_bound(a+1,a+1+n,i)-a,M=m,s=0;
		for(int j=x;j>=1&&M>i-a[j];j--)s++,M-=(i-a[j]);
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
