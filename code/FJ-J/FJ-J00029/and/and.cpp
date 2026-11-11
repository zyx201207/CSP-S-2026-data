#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=31;
int n,m,g,a[N],i,j,k,ans,s;
bool cmp(int x,int y) {return ((x&-x)>(y&-y))||((x&-x)==(y&-y)&&x>y);}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1),g=unique(a+1,a+n+1)-a-1,m-=(n-g),n=g;
	if(n<=20) for(k=0;k<(1<<n);++k) {
		for(i=s=0;i<n;++i) s+=(k>>i)&1;
		if(s!=m) continue ;
		for(i=0,s=(1<<30)-1;i<n;++i) if((k>>i)&1) s&=a[i+1];
		ans=max(s,ans);
	}else if(m==n) for(i=2,ans=a[1];i<=n;++i) ans&=a[i];
	else if(m==1) for(i=1;i<=n;++i) ans=max(ans,a[i]);
	else {
		sort(a+1,a+n+1,cmp);
		for(i=2,ans=a[1];i<=m;++i) ans&=a[i];
	}
	return cout<<ans,0;
}
// rp++;
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7
*/
