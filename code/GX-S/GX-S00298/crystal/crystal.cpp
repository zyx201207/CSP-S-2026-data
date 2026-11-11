#include<cstdio>
#include<algorithm>
int n,ans;
long long m,a[501145]={},S[501145]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i];
	for(int L=1,R=n,mid,tg;L<=R;){
		mid=(L+R)>>1,tg=0;
		for(int st=1,ed=mid;ed<=n;st++,ed++) if(a[ed]*mid-S[ed]+S[st-1]<=m){
			tg=1;
			break;
		}
		if(tg) ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
