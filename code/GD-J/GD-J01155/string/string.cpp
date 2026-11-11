#include<iostream>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;long long ans=0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d %c", &a[i], &c[i]);
	for(int i=1, j=n, k1=0, k2=0;i<j;){
		if(a[i]-k1>a[j]-k2){
			ans+=(c[i]!=c[j])*(a[j]-k2);
			k1+=a[j]-k2;
			j--;k2=0;
		}else{
			ans+=(c[i]!=c[j])*(a[i]-k1);
			k2+=a[i]-k1;
			i++;k1=0;
		}
	}
	printf("%lld", ans);
	return 0;
} 
