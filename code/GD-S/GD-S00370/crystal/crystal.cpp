#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
long long b=0;
int main(){
	freopen("fre.in","r",stdin);
	freopen("fre.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long c=a[n/2+1];
	for(long long i=1;i<=n;i++){
		if(a[i]==c) b++;
		for(long long j=1;j<=m;j++){
			if(a[i]<c){
				a[i]=c;
				b++;
				m=m-(c-a[i]);
			}
		}
	}
	printf("%lld",b);
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 

