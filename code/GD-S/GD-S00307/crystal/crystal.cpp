#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n,m,a[N],c,cnt,l=1,i,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		c=a[i]-a[i-1];
		while((i-l)*c>m-cnt){
			cnt=cnt-(a[i]-a[l])+c;
			l++;
		}
		ans=max(ans,i-l+1);
		cnt+=c*(i-l);
	}
	printf("%lld",ans);
} 
