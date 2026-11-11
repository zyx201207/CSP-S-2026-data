#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
#define f(i,l,r) for(int i=l,R##R=r;i<=R##R;++i)
#define g(i,l,r) for(int i=l,R##R=r;i>=R##R;--i)
const int N=5e5+10;
int n,m,as,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n,j=n,s=0;i;--i){
		while(j&&s+a[i]-a[j]<=m) s+=a[i]-a[j],--j;
		as=max(as,i-j),s-=(a[i]-a[i-1])*(i-j-1);
	}
	cout<<as;
	return 0;
}
