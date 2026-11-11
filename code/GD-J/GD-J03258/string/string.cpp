#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	rep(i,1,n)cin>>a[i]>>c[i];
	int l=1,r=n;
	ll ans;
	while(l<r){
		int mn=min(a[l],a[r]);
		a[l]-=mn,a[r]-=mn;
		if(c[l]!=c[r])ans+=mn;
		if(!a[l])++l;
		if(!a[r])--r;
	}cout<<ans;
	return 0;
}
