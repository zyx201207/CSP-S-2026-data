#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+500;
ll a[N],sum[N];
int n,b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll len=0;
    for(int i=1;i<=n;i++){
    	char c;
    	scanf("%lld",&a[i]);
    	sum[i]=sum[i-1]+a[i];
    	len+=a[i];
    	cin>>c;
    	b[i]=c-'a';
	}
	ll l=0,r=0,kl=0,kr=0,rl=0,rr=0;
	if(len&1)l=len/2+1,r=len/2+1;
	else l=len/2,r=len/2+1;
	for(int i=1;i<=n;i++){
		if(l<=sum[i]){
			kl=i;
			rl=l-sum[i-1];
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(r<=sum[i]){
			kr=i;
			rr=sum[i]-r+1;
			break;
		}
	}
	ll ans=0;
	while(l>=1&&r<=len){
		if(rl==0)kl--,rl=a[kl];
		if(rr==0)kr++,rr=a[kr];
		if(rl>=rr){
			if(b[kl]!=b[kr])ans+=rr;
			r+=rr;
			l-=rr;
			rl-=rr;
			rr=0;
		}else{
			if(b[kl]!=b[kr])ans+=rl;
			r+=rl;
			l-=rl;
			rr-=rl;
			rl=0;
		}
	}
	cout<<ans;
	return 0;
}

