#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
ll len,pre[N],suf[N];
char c[N][10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],c[i]);
		len+=a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=n;i;i--)
		suf[i]=suf[i+1]+a[i];
	ll l=1,r=len;
	ll ans=0;
	int i=1,j=n;
	while(l<=r){
	//	printf("i:%d j:%d\n",i,j);
		if(c[i][0]!=c[j][0])ans+=min(a[i],a[j]);
		l+=min(a[i],a[j]);
		r-=min(a[i],a[j]);
		int x=a[i];
		a[i]-=min(a[i],a[j]);
		a[j]-=min(x,a[j]);
		if(!a[i])i++;
		if(!a[j])j--;
	}
	printf("%lld\n",ans);
}