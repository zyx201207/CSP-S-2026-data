#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int n;
long long m,a[MAXN],s[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=a[i]+s[i-1];
	}
	int ans=0,p=1;
	for(int i=1;i<=n;++i){
		while(p<i&&(__int128)(i-p+1)*a[i]>m+(s[i]-s[p-1]))++p;
		ans=max(ans,i-p+1);
	}
	cout<<ans<<'\n';
}
