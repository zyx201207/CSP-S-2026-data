#include<bits/stdc++.h>
#define int long long
#define maxn (int)5e5+5
using namespace std;
int n,m,a[maxn],ans=0,p,c;
signed main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n,[](int a,int b)->bool{return a>b;});
	for(int i=1;i<n;i++){
		p=m;
		c=1;
		for(int j=i+1;j<=n;j++){
			p=p-a[i]+a[j];
			if(p>=0) c++;
			else break;
			if(ans>(c+n-j)) break;
		}
		ans=ans>c?ans:c;
		if(ans>=(n-i+1)) break;
	}
	printf("%lld\n",ans);
	return 0;
}
