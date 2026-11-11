#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500000;
int n,p,ans;ll sum,m,a[N+5];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1),p=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-p+1)-sum>m) sum-=a[p],++p;
		ans=max(ans,i-p+1);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
