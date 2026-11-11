#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[202020],p[202020];
char c[202020];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",a+i,c+i);
		p[i]=p[i-1]+a[i];
	}
	int pos=lower_bound(p+1,p+n+1,p[n]/2)-p,tmp=a[pos];
		//printf("l: %lld",p[n/2]-p[pos-1]);
	if(p[n]&1) a[pos]-=2*min(p[pos]-(p[n]/2),p[n]/2-p[pos-1]+1)-1;
	else a[pos]-=2*min(p[pos]-p[n]/2,p[n]/2-p[pos-1]);
	//printf("pos: %lld\n",a[pos]);
	if(p[pos-1]+tmp/2>p[n]/2) pos--;
		//printf("# %lld\n",pos);
	for(ll l=pos,r=pos+1;l>0&&r<=n;){
		while(l>0&&a[l]<=a[r]) ans+=a[l]*ll(c[l]!=c[r]),a[r]-=a[l],l--;
			//printf("-> %lld\n",ans);
		while(r<=n&&a[r]<=a[l]) ans+=a[r]*ll(c[l]!=c[r]),a[l]-=a[r],r++;
			//printf("-> %lld\n",ans);
	}
	if(p[n]%2&&ans>p[n]/2) ans=p[n]-ans;
	printf("%lld",ans);
	return 0;
}
/*
4
2 a
5 b
3 a
3 c

2
2 a
5 b

3
2 b
3 a
2 b

4
2 a
5 a
3 b
5 b
*/
