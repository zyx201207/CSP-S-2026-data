#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,a[N];ll ans;
char c[N],s[3];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d %s",a+i,s),c[i]=s[0];
	int cnt1=a[1],cnt2=a[n];char c1=c[1],c2=c[n];
	for(int i=1,j=n;i<=n&&j>=1;){
		int res=min(cnt1,cnt2);
		ans+=(c1!=c2)*res,cnt1-=res,cnt2-=res;
		if(!cnt1) cnt1=a[++i],c1=c[i];
		if(!cnt2) cnt2=a[--j],c2=c[j];
	}printf("%lld",ans>>1);
	return 0;
} 
