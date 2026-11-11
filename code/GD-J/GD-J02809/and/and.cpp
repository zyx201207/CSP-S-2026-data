#include<bits/stdc++.h>
using namespace std;
long long a[202020],n,m,ans,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=29;i>=0;i--){
		c=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1) c++;
		}
		if(c>=m){
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1)) a[j]=0;
			}
			ans+=(1LL<<i);
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
