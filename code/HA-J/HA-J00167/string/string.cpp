#include<bits/stdc++.h>
using namespace std;
#define lll long long
#define ull unsigned long long
#define u_map unordered_map
const lll N=2e5+10,INF=0x3f3f3f3f,LINF=1e18+1;
lll n,a[N],sum;
char c[N];
lll l,r,ans,ll,rr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0){
		int li=1,ri=n;
		while(ll+rr!=sum){
			l=a[li],r=a[ri];
			ll+=l,rr+=r;
			if(ll>sum/2){
				int mr=ll-sum/2;
				ll=sum/2;
				l-=mr;
			}
			if(rr>sum/2){
				int mr=rr-sum/2;
				rr=sum/2;
				r-=mr;
			}
			int need=min(l,r);
			if(c[li]!=c[ri]) ans+=need;
			l-=need,r-=need;
			if(l==0) li++;
			if(r==0) ri--;
		}
	}else{
		int li=1,ri=n;
		l=a[li],r=a[ri];
		ll+=l,rr+=r;
		while(ll+rr+1!=sum){
			if(ll>sum/2){
				int mr=ll-sum/2;
				ll=sum/2;
				l-=mr;
			}
			if(rr>sum/2){
				int mr=rr-sum/2;
				rr=sum/2;
				r-=mr;
			}
			int need=min(l,r);
			if(c[li]!=c[ri]) ans+=need;
			l-=need,r-=need;
			if(l==0) li++,l=a[li],ll+=l;
			if(r==0) ri--,r=a[ri],rr+=r;
		}
	}
	cout<<ans;
	return 0;
}
