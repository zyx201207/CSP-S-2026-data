#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const int INF=INT_MAX/3,N=2e5+20;
ll l_len=0,r_len=0,n,ans,a[N];
char c[N];
int main(){
	fop("string");
	scanf("%lld",&n);
	rep(i,1,i<=n,1) scanf("%lld %c",&a[i],&c[i]);
	ll l=1,r=n;
	l_len=a[l],r_len=a[r];
//	cout<<a[2];
	while(l<r){
		if(l_len>r_len){
			if(c[l]!=c[r]) ans+=r_len; 
			l_len-=r_len,r_len=0;
			r--;
			if(!r) break;
			r_len=a[r];
		}else if(l_len<r_len){
			if(c[l]!=c[r]) ans+=l_len;
			r_len-=l_len,l_len=0;
			l++;
			if(l>n) break;
			l_len=a[l];
		}else {
			if(c[l]!=c[r]) ans+=r_len;
			r_len=0,l_len=0;
			l++,r--;
			if(!r||l>n) break;
			l_len=a[l],r_len=a[r];
		}
//		cout<<l<<' '<<l_len<<"\n";
//		cout<<r<<' '<<r_len<<"\n";
//		cout<<"\n";
	}
	printf("%lld",ans);
	return 0;
}

