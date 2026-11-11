#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500005;
ll n,m,a[N],qzh[N],l,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		l=1,r=i;
		while(l<r-1){
			ll mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(qzh[i]-qzh[mid-1])>m) l=mid;
			else r=mid;
		}
		if(a[i]*(i-l+1)-(qzh[i]-qzh[l-1])<=m) ans=max(ans,i-l+1);
		else ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
