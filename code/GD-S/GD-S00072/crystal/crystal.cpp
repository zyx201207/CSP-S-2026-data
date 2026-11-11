#include<bits/stdc++.h>
#define ll long long
#define rep(i,X,Y) for(int i=(X);i<=(Y);i++)
#define per(i,X,Y) for(int i=(X);i>=(Y);i--)
using namespace std;

constexpr int N=5e5+10;

int n;
ll m,a[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=1; ll sum=0;
	rep(i,1,n) {
		sum+=a[i];
		while(l<=i&&a[i]*(i-l+1)-sum>m) {
			sum-=a[l]; l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
