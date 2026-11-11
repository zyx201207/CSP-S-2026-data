//GZ-J00425 王武涛 兴义市弘毅中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//变量区
const ll MAX=2e5+10;
ll n,m,i,j,dp[MAX],a[MAX];

//函数区


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	//代码区
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		dp[i]=a[1];
	}
	for(i=2;i<=n;i++){
		for(j=m;j>=1;j--){
			dp[j]=max(a[j],d[j-1]&a[j]);	
		}
	}
	printf("%lld",d[m]);
	
	return 0;
}

