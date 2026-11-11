#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	int j=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while((i-j)*a[i]-(s[i-1]-s[j-1])>m && j<=i)j++;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
