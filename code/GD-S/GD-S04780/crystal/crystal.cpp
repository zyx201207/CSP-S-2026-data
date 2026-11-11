#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],c[N],q[N],hh=1,tt,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++)
		c[i]=a[i]-a[i-1];
	for(ll i=1;i<=n;i++){
		ll siz=tt-hh+1;
	//	printf("head:%lld tail:%lld size:%lld\n",hh,tt,siz);
		ans=max(ans,siz);
		sum+=c[i]*siz;
	//	printf("\n");//
	//	for(ll i=hh;i<=tt;i++)
	//		printf("%lld ",q[i]);//
	//	printf("\n");//
		if(sum<=m){
			q[++tt]=i;
			ans=max(ans,siz);
		}else{
			while(sum>m){
		//		printf("TRg\n");
				sum-=(a[i]-a[q[hh]]);
				hh++;
				siz=tt-hh+1;
			}q[++tt]=i;
			ans=max(ans,siz);
		}siz=tt-hh+1;;
	//	printf("head:%lld tail:%lld size:%lld\n",hh,tt,siz);
		ans=max(ans,siz);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
