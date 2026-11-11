#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll n,sum[N],arr[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&arr[i],&c[i]);
		sum[i]=sum[i-1]+arr[i];
	}
	ll s=sum[n],cnt=0;
	for(int i=1;i<=n;i++){
		ll l=sum[i-1]+1,r=sum[i];
		ll newr=s-l+1,newl=s-r+1;
		ll kl=upper_bound(sum+1,sum+n+1,newl)-sum-1;
		ll kr=lower_bound(sum+1,sum+n+1,newr)-sum;
		if(sum[kl]<newl)kl++;
		if(sum[kr]<newr)kr++;
		//cout<<kl<<" "<<kr<<endl;
		for(int j=kl;j<=kr;j++){
			if(c[i]!=c[j])cnt+=min(newr,sum[j])-max(newl-1,sum[j-1]);
		}
		//cout<<kl<<" "<<kr<<endl;
	}
	printf("%lld",cnt/2);
	return 0;
}
//freopen("sting1.ans","W",stdin);


