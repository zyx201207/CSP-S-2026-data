#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],sum[500010];
long long n;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	sum[0]=0,a[0]=0;
	bool t=true;
	int ans;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		//printf("%d %lld %lld ",i,sum[i],sum[i-1]);
		//printf("%lld %lld\n",a[i],a[i-1]);
		if(sum[i]>m){
			ans=i-1;
			t=false;
			break;
		}
		else if(sum[i]==m){
			ans=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]) ans++;
				else break;
			}
			t=false;
			break;
		}
	}
	if(t) ans=n;
	printf("%d",ans);
	fclose(stdin); 
	fclose(stdout);
	return 0;
} 
