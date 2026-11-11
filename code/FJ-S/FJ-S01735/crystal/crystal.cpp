#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans,a[N],c[N],s[N];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	if(a[1]<0) for(int i=n;i;i--) a[i]-=a[1];
	ll l=1,r=1,cnt=0;
	for(;r<=n;){
		if(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		else{
			ans=max(ans,r-l+1ll);
			cnt+=(r-l+1)*c[r];
			r++;
		}
	}
	cout<<ans;
	return 0;
}
