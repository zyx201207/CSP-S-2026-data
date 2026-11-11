#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn=-2e9,maxa=-2e9;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]-a[i-1];
	}
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			if(s[i]-s[j-i-1]<=m&&i-j+1>maxn){
				maxn=i-j+1;
				maxa=s[i]-s[j-i-1];
				break;
			}
		}
	}
	printf("%lld",maxn);
	return 0;
}

