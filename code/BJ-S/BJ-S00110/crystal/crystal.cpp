#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int k=0;
	for(int i=n;i>=1;i--){
		for(int j=k+1;i-j+1>=1;j++){
			if(a[i]*j-s[i]+s[i-j]>m)
				break;	
			k=j;
		}
	}
	printf("%d",k);
	return 0;
}
