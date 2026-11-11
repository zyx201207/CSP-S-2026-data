#include<bits/stdc++.h>
using namespace std;
long long a,s,d=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&a,&s);
	long long d[s+1];
	for(int i=0;i<s;i++){
		scanf("%lld",&d[i]);
		d=max(d,d[i]);
	}
	printf("%lld",d);
	return 0;
} 
