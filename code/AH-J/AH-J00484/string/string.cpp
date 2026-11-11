#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],b[200002],l;
char c[200002],d[1000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf(" %c",&c[i]);
		for(int j=1;j<=a[i];j++){
			d[l+j]=c[i];
		}
		l+=a[i];
	}
	int cnt=0;
	for(int i=1;i*2<=l;i++){
		if(d[i]!=d[l-i+1]){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
