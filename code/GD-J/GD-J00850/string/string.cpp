#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[200005],r,l,rr,ll,s,ss;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>dp[i]>>c[i];
	r=0,l=n+1;
	while(1){
		if(rr==0){
			r++;
			rr+=dp[r];
		}
		if(ll==0){
			l--;
			ll+=dp[l];
		}
		if(rr>=ll){
			ss=ll;
			rr-=ll;
			ll=0;
		}
		else{
			ss==rr;
			ll-=rr;
			rr=0;
		}
		if(c[r]!=c[l]) s+=ss;
		if(r+1==l && (rr==0 || ll==0)){
			cout<<s;
			return 0;
		}
	}
	return 0;
}
