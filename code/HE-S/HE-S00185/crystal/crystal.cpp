#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	long long l=1,r=1,len=1,k=0;
	while(r<=n){
		r++;
		k+=(a[r]-a[r-1])*len;
		len++;
		while(k>m){
			k-=a[r]-a[l];
			l++;
			len--;
		}
		ans=max(ans,len);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/ 
 
