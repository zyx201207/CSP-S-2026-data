#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,ans=0;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=sum,ll=1,rr=n;
	long long cnl=1,cnr=n;
	long long sum2=sum/2;
	ll=min(sum2,a[cnl]);
	rr=max(sum2,sum-a[cnr]+1);
	while(l<=sum2){
		long long k=min(ll-l+1,r-rr+1);
		if(c[cnl]!=c[cnr]){
			ans+=k;	
		}
		if(k==ll-l+1){
			l=ll;
			cnl++;
			ll=min(sum2,l+a[cnl]);
			l+=1;
			r=sum-l+1;
		}
		else{
			r=rr;
			cnr--;
			rr=max(sum2,r-a[cnr]);
			r-=1;
			l=sum-r+1;
		}
	}
	cout<<ans;
	return 0;
}
