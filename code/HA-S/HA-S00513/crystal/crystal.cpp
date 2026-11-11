#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
long long m,ans=0,a[500010],c[500010],sum[500010],sum1=0,sum2=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	c[0]=0;
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	sum1=c[1];
	for(int i=1;i<n;i++){
		if(c[i]==sum1) sum2++;
	}
	if(sum2==n-1){
		long long ci=1;
		while(m-sum1*ci>=0){
			m-=sum1;
			ci++;
			cnt++;
		}
		printf("%d",cnt+1);
		return 0;
	}
	sum[1]=0;
	for(int i=1;i<n;i++){
		ans+=c[i]*i;
		sum[i+1]=ans;
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i-cnt;j++){
			if(sum[i]-sum[j]<=m&&i>j){
				cnt=max(cnt,i-j+1);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

