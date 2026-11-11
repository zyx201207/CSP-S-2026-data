#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],b[N],l=1,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=r;
		r+=a[i];
	}
	ll li=1,ri=n;
	while(li<ri){
		ll m=l+a[li]-1;
		while(l<=m&&r>b[ri]){
			ll s=m-l+1,t=r-b[ri];
			ll res=min(s,t);
			if(c[li]!=c[ri])
				ans+=res;
			l+=res;
			r-=res;
			if(r<=b[ri])
				ri--;
			if(li==ri)
				break;
		}
		li++;
	}
	cout<<ans<<'\n';
	return 0;
}
