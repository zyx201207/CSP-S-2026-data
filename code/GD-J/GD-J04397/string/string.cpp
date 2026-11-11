#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long s[200005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	auto l=(s[n]+1)/2,r=s[n]/2+1;
	if(l==r){
		l--;
		r++;
	}
	while(l>0&&r<=s[n]){
		int pl=upper_bound(s+1,s+n+1,l)-s,pr=lower_bound(s+1,s+n+1,r)-s;
		if(s[pl]-a[pl]>=l)pl--;
		auto sz=min({l-s[pl-1],s[pr]-r+1,l,s[n]-r+1});
		if(c[pl]!=c[pr])ans+=sz;
		l-=sz;
		r+=sz;
	}
	cout<<ans;
	return 0;
}
