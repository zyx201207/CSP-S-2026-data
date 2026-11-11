#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,y,z) for(int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
const int N=200005;
int n;
ll a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int nx=min(a[l],a[r]);
		a[l]-=nx,a[r]-=nx;
		if(c[l]!=c[r])ans+=nx;
		if(a[l]<=0)++l;
		if(a[r]<=0)--r;
	}
	cout<<ans<<endl;
	return 0;
}
