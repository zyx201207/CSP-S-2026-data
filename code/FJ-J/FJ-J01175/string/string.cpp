#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
int l=1,r,ll,rr,ans;
char lls,rrs;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	} 
	//aaaaabbcaaaaabbbbbaaaaaaaaaaaa
	/*
	6
	5 a
	2 b
	1 c
	5 a
	5 b
	12 a*/
	r=n;
	ll=a[1],rr=a[n];
	lls=c[1],rrs=c[n];
	//cout<<"l:"<<l<<" "<<"r:"<<r<<" "<<"ll:"<<ll<<" "<<"rr:"<<rr<<" "<<"lls:"<<lls<<" "<<"rrs:"<<rrs<<" "<<"ans:"<<ans<<endl;
	while(l<r){ 
		//cout<<"###l:"<<l<<" "<<"r:"<<r<<" "<<"ll:"<<ll<<" "<<"rr:"<<rr<<" "<<"lls:"<<lls<<" "<<"rrs:"<<rrs<<" "<<"ans:"<<ans<<endl;
		if(ll<rr){
			if(lls!=rrs){
				ans+=ll;
			}
			rr-=ll;
			l++;
			ll=a[l];
			lls=c[l];
		}
		else if(ll==rr){
			if(lls!=rrs){
				ans+=ll;
			}
			l++;
			r--;
			ll=a[l];
			lls=c[l];
			rr=a[r];
			rrs=c[r];
		}
		else{
			if(lls!=rrs){
				ans+=rr;
			}
			ll-=rr;
			r--;
			rr=a[r];
			rrs=c[r];
		}
		//cout<<"l:"<<l<<" "<<"r:"<<r<<" "<<"ll:"<<ll<<" "<<"rr:"<<rr<<" "<<"lls:"<<lls<<" "<<"rrs:"<<rrs<<" "<<"ans:"<<ans<<endl;
	}
	printf("%lld",ans);
	return 0;
}
