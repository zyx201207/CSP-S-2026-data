#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll l,r,ans,anss,n,m,a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i,1,n){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		s[i]=s[i-1]+a[i];
	}
	rep(i,1,n){
		l=1,r=i;anss=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				anss=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-anss+1);
	}
	cout << ans;
	return 0;
}
