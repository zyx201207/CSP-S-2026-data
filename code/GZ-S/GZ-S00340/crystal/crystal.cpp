//GZ-S00340 遵义市第一中学 胡明轩 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,tmp,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		tmp=0,s=0;
		for(int j=i;j>=1;j--){
			if(tmp+a[i]-a[j]<=m){
				s++;
				tmp+=a[i]-a[j];
			}	
		}ans=max(ans,s);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


