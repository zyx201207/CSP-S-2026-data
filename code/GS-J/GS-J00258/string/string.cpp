#include<bits/stdc++.h>
using namespace std;

#define N 1000000005

char word[N],w[N],h[N];
long long a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a,i;
	scanf("%lld",&n);
	for(long long i=0;i<n;++i){
		scanf("%lld",&a[i]);
		scanf("%s",word[i]);
	}
	
	for(int i=0;i<=3000000000;++i){
		printf("%d",i);
	}
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
