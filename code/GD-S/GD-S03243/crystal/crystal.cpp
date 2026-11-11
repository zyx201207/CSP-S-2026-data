#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],def=0,ans=1,r,nw=0;
long long s[500005],t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;++i) s[i]=a[i+1]-a[i];
	for(int i=n-1;i>=1;--i) t[i]=s[i]+t[i+1];
	r=n-1;
	for(int i=n-1;i>=1;--i){
		nw+=t[i]-def;
		if(nw>m){
			for(int j=r;j>=i;--j){
				nw-=(j-i+1)*s[j];
				def+=s[j];
				--r;
				if(nw<=m) break;
			}
			ans=max(ans,r-i+2);
		}
		else ans=max(ans,r-i+2);
	}
	cout<<ans;
	return 0;
}
