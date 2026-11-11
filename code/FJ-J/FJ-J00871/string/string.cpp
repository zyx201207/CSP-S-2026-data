#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[200005],ans=0;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll lt=1,rt=n,la=a[1],ra=a[n],minn;
	char lc=c[1],rc=c[n];
	while(lt<rt){
		minn=min(la,ra);
		if(lc!=rc){
			ans+=minn;
		}
		la-=minn;
		ra-=minn;
		if(la==0){
			lt++;
			la=a[lt];
		}
		if(ra==0){
			rt--;
			ra=a[rt];
		}
		lc=c[lt];
		rc=c[rt];
	}
	cout<<ans;
	return 0;
}
