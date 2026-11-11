#include<bits/stdc++.h>

using namespace std;
using ll =long long;
const int N = 5e5+10;
ll n,m,a[N],dp[N],c,p;
bool f = false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==2)c = a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	if(c > m){
		printf("%d",1);
		return 0;
	}
	for(int i=1;true;i++){
		if(p+(i-1)*c<=m)p+=(i-1)*c;
		else {
			printf("%d",i-1);
			return 0;
		}
	}
	return 0;
}