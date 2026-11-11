//GZ-S00359 贵州省黔西第一中学 代毅承
#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long n,m,a[maxn],ans=-1,hh=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		long long l=i,pow=m,num=0;
		while(pow){
			long long cha=a[i]-a[l];
			if(cha<=pow&&l>0){
				pow=pow-cha;
				l--;
				num++;
			}
			if(cha>pow||l<=0){
				pow-=cha;
				break;
			}
		}
		ans=max(ans,num);
	}
	printf("%lld",ans);
}
