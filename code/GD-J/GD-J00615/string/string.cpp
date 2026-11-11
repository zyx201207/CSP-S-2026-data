#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,ans,sum,a[N],s[N],mid,m,r,im;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		getchar();
		c[i]=getchar();
		s[i]=a[i]+s[i-1];
		sum+=a[i];
	}
	mid=sum/2;
	for(ll i = 1;i<=n;i++){
		if(s[i]>mid){
			im=s[i];
			break;
		}
	}
	for(ll i=1,j=n;s[i]<=im&&s[j]>=sum-mid+1;){
		bool b;
		if(a[i]<a[j]){
			r=a[i];	
			a[j]-=r;
			b=1;
		}
		else{
			r=a[j];
			a[i]-=r;
			b=0;
		}
		if(c[i]!=c[j]) ans+=r;
		if(b){
			i++;
		}
		else{
			j--;
		}
	}
	printf("%lld",ans);
	return 0;
}
