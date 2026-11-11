//GZ-J00025 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],r,ans,sum[200010],l=1;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;n>=i;i++){
		scanf("%lld %c",&a[i],&c[i]);
		sum[i]=sum[i-1]+a[i];
	}
	r=n;
	c[0]=c[1];
	c[n+1]=c[n];
	while(r>=l){
		if(sum[l-1]==sum[n]-sum[r]){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			l++;
			r--;
		}
		else if(sum[l-1]>sum[n]-sum[r]){
			if(c[l-1]!=c[r]){
				ans+=min(sum[l-1]-sum[n]+sum[r],a[r]);
			}
			r--;
		}
		else{
			if(c[l]!=c[r+1]){
				ans+=min(sum[n]-sum[r]-sum[l-1],a[l]);
			}
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
