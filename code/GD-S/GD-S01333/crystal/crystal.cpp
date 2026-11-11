#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m,sum=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-j+1)-sum>m) sum-=a[j++];
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
