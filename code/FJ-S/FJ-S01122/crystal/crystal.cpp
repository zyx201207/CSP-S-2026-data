/*
-fsanitize=address,undefined

ios::sync_with_studio(0);
cin.tie(0);

cout<<fixed<<precision();
*/
#include <bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define pii pair<int,int>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;

namespace mycode{
	const int MAXN=5e5+5;
	ll a[MAXN],S[MAXN],m;
	int n;
	ll lbd(int l,int r,ll idx){//000111
		int mid;
		while(l<r){
			mid=(l+r)>>1;
			if(((ll)idx-mid)*a[idx]-(S[idx-1]-S[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		return idx-l+1;
	}
	int main(){
		scanf("%d%lld",&n,&m);
		FOR(i,1,n) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		S[0]=0;
		FOR(i,1,n) S[i]=S[i-1]+a[i];
		ll ans=0;
		FOR(i,1,n) ans=max(ans,lbd(1,i,i));
		printf("%lld",ans);
		return 0;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	mycode::main();
	return 0;
}
