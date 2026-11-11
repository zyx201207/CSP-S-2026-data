#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL N=2e5+10;
LL n,a[N],ai[N],sum,rest1=0,rest2=0,cnt,m;
char c[N],ci[N];
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	cin>>a[i]>>c[i],sum+=a[i];
	LL cnt=0,l=1,r=n;
	if(sum<=1e8){
		for(LL i=1;i<=n;++i)	
		for(LL j=1;j<=a[i];++j)	str+=c[i];
		for(LL i=1;i<=sum/2;++i)	cnt+=(str[i-1]!=str[sum-i]);	
	}
	else{
		while(l<r){
			if(rest1){
				if(rest1<=a[l])	a[l]-=rest1,cnt+=rest1,rest1=0,r--;
				else{
					 while(rest1){
						 if(rest1>=a[l])	rest1-=a[l],cnt+=c[l]==c[r]?0:a[l],l++;
						 else a[l]-=rest1,cnt+=c[l]==c[r]?0:rest1,rest1=0,r--;
					 }
				 }
			}
			if(rest2){
				if(rest2<=a[r])	a[r]-=rest2,cnt+=rest2,rest2=0,l++;
				else{
					 while(rest2){
						 if(rest2>=a[r])	rest2-=a[r],cnt+=c[l]==c[r]?0:a[r],r--;
						 else a[r]-=rest2,cnt+=c[l]==c[r]?0:rest2,rest2=0,l++;
					 }
				 }
			}
			//cout<<l<<' '<<r<<' '<<cnt<<' '<<rest1<<' '<<rest2<<'\n';
			if(l>=r)	break;
			if(c[l]==c[r]){
				if(a[l]>a[r])	rest2+=a[l]-a[r],a[l]-=a[r],r--;
				else if(a[l]==a[r])	l++,r--;
				else rest1+=a[r]-a[l],l++;
			}
			else{
				if(a[l]>a[r])	rest2+=a[l]-a[r],a[l]-=a[r],cnt+=a[r],r--;
				else if(a[l]==a[r])	cnt+=a[l],l++,r--;
				else rest1+=a[r]-a[l],cnt+=a[l],l++;
			}
			//cout<<l<<','<<r<<' '<<cnt<<' '<<rest1<<' '<<rest2<<'\n';
			
			
		}
	}	
	printf("%lld",cnt);
	return 0;
}
