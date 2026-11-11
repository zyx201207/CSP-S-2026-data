#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(false)
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=2e5+5;
int T,n,m,ans;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	Tie,cin>>n>>m,ans=INT_MAX;
	rep(i,1,n) cin>>a[i];
	ref(i,30,0)
	{
		int tn=0;
		rep(j,1,n) if((a[j]>>i)&1) swap(a[j],a[++tn]);
		if(tn>=m) n=tn;
	}
	rep(i,1,m) ans&=a[i];
	cout<<ans;
	return 0;
}//100pts