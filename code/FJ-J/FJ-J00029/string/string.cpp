#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,a[N],i,l,r; char c[N]; ll ans;
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<=r) {
		ans+=(c[l]==c[r]?0:min(a[l],a[r]));
		if(a[l]<a[r]) a[r]-=a[l],++l;
		else if(a[l]>a[r]) a[l]-=a[r],--r;
		else a[l]=a[r]=0,++l,--r;
	}
	return cout<<ans,0;
}
// rp++;
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 c
2 b
2 a
*/
