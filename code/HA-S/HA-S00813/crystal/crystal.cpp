//(^-^)
#include<bits/stdc++.h>
#define ll long long
#define N 1000050
using namespace std;
ll n,m,a[N],ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (ll l=1;;){
		ll s=0;
		ll r=l+1;
		for (;r<=n;){
			if (s+(a[r]-a[r-1])*(r-l)<=m) {
				s+=(a[r]-a[r-1])*(r-l);
				ans=max(ans,r-l+1);
				r++;
			}else if (l!=r) {
				s-=a[r]-a[l];
				l++;
			}else break;
		}
		if (l==n||r==n) break;
		else ++l;
	}
	cout<<ans;
	return 0;
}
