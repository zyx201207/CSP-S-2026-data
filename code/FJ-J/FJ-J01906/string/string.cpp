#include<bits/stdc++.h>
using namespace std;

int n,a[200010];
char c[200010];
long long sum,sum_xg;

int main(){
	freopen("string.in","in",stdin);
	freopen("string.out","out",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		sum+=a[i];
	}
	sum/=2;
	for(long long i1=1,i2=n,s1=a[1],s2=a[n];;){
		if(s1>sum&&s2>sum) break;
		else if(s1==sum&&s2==sum){
			if(c[i1]!=c[i2]) sum_xg+=a[i1];
			break;
		}else if(a[i1]<a[i2]){
			if(c[i1]!=c[i2]) sum_xg+=a[i1];
			a[i2]-=a[i1]; i1++; s1+=a[i1];
		}else if(a[i1]>a[i2]){
			if(c[i1]!=c[i2]) sum_xg+=a[i2];
			a[i1]-=a[i2]; i2--; s2+=a[i2];
		}else if(a[i1]==a[i2]){
			if(c[i1]!=c[i2]) sum_xg+=a[i1];
			i1++; i2--; s1+=a[i1]; s2+=a[i2];
		}
	}
	printf("%lld",sum_xg);
	return 0;
}
