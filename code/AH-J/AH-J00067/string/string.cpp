#include<bits/stdc++.h>
using namespace std;
#define int long long
struct zf{
	int a;
	char b;
}ai[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	cerr<<1;
	int tt=0;
	for(int x=1;x<=n;x++){
		cin>>ai[x].a>>ai[x].b;
		tt+=ai[x].a;
	}
	if(n==1){
		cout<<0;return 0;
	}
	int l=1,ll=ai[1].a,r=n,rr=ai[n].a,ans=0;
	while(tt>0){
		if(l==r){
			tt=0;
		}
		else{
			if(ll<rr){
				if(ai[l].b!=ai[r].b)ans+=ll;
				rr-=ll,tt-=ll;
				ll=ai[++l].a;
			}
			else{
				if(ai[l].b!=ai[r].b)ans+=rr;
				ll-=rr,tt-=rr;
				rr=ai[--r].a;
			}
		}
	}cout<<ans;
	return 0;
}
