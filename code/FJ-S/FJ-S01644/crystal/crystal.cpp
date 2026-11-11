#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define endl '\n'
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=5e5+5;
ll a[N];
int n;
ll m;
ll s[N];
ll calc(int l,int r) {
	return 1ll*a[r]*(r-l+1)-(s[r]-s[l-1]);
}
int main() {
	fin("crystal.in");fout("crystal.out");
	ios::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	fo(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	fo(i,1,n) s[i]=s[i-1]+a[i];
	int ans=0;
	fo(i,1,n) {
		int l=1,r=i;
		while(l<r) {
			int mid=(l+r)>>1;
			if(calc(mid,i)<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}