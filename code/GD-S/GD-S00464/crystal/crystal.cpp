#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
long long m;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i=i+1)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);//保持单调性 
	int st=1;
	for(int i=1;i<=n;i=i+1)sum[i]=sum[i-1]+a[i];//前缀和预处理 
	for(int i=1;i<=n;i=i+1){//st为左指针 
		while(st<i&&sum[i]-sum[st-1]+m<a[i]*(i-st+1))st=st+1;
		ans=max(ans,i-st+1);
	//end-of-i
	}
	printf("%d\n",ans);
	return 0;
//crystal-T1
//测试样例通过情况：001ok. 002ok. 003ok. 004ok.
//检查情况：18:11:08.71
} 
