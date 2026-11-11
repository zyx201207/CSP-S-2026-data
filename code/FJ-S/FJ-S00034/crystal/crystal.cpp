#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,i,ans,l,r,mid; ll m,a[N],b[N];
bool check(int j) {
	return a[i]*(i-1)-b[i-1]-a[i]*(j-1)+b[j-1]<=m; 
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i) b[i]=b[i-1]+a[i];
	for(i=1;i<=n;++i) {
		l=1,r=i;
		while(l<=r) check(mid=(l+r)/2)?r=mid-1:l=mid+1;
		ans=max(ans,i-l+1);
	}
	return cout<<ans,0;
} 
/*
5 5
1 2 4 8 9

5 8
-5 -1 2 2 7

4 91
13 78 91 91
*/ 
