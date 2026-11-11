#include<bits/stdc++.h>
using namespace std;

long long a[1000000000000000001],n,m,ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1); 
	long long ans=m,sum=0;
	for(int i=n/2;i>=1;i--){
		int mi=a[n/2+1]-a[i];
		if(mi<=ans){
			ans-=mi;
			sum++;
		}else {
			break;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==a[n/2+1])
			sum++;
	ma=max(ma,sum); 
	ans=m,sum=0;
	for(int i=n;i>=n/2;i--){
		int mi=a[n]-a[i];
		if(mi<=ans){
			ans-=mi;
			sum++;
		}else{
			break;
		} 
	}
	for(int i=1;i<=n;i++)
		if(a[i]==a[n])
			sum++;
	ma=max(ma,sum);  
	printf("%lld",ma);
	return 0;
}
