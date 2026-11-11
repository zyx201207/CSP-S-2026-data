#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=5e5+5;
const long long M=1e18+5;
/*
dp[i]:第i个水晶结尾，最多能达到的能量水晶数量。 
*/
long long n,m,m2,a[N],dp[N];
long long f(long long step,int num,int cnt,long long len){//以cnt结尾最多能达到的能量水晶数量。 
	if(step<a[cnt]-a[num]||num<1){
		m2=step;
		return len;
	}
	return f(step-a[cnt]+a[num],num-1,cnt,len+1);
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	m2=m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==a[i-1]){
			dp[i]++;
			continue;
		}
		if(a[i]<a[i-1]) m2=m;
		long long x=f(m2,i-1,i,1);
		long long y=f(m,i-1,i,1);
//		cout<<x<<endl;
//		cout<<m2<<endl;
		if(x>dp[i]) dp[i]=x;
		else if(y>dp[i]) dp[i]=y,m2=m;
//		cout<<dp[i]<<endl;
	}
	printf("%lld",dp[n]);
//	system("fc crystal.out crystal4.ans");
	return 0;
}
