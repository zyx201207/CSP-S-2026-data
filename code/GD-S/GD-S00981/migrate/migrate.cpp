#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e[2000005],f[2000005],g=1,h[2000005];
int main(){
	scanf("%lld %lld",&a,&b);
	for(int i=1;i<=b;i++){
		scanf("%lld %lld",&c,&d);
		for(int j=1;j<=c;j++){
			scanf("%lld",&e[j]);
		}
		g=1;
		for(int j=2;j<=c;j++){
			while(e[j]-e[g]>d){
				g++;
			}
			f[j]=g;
			h[j]=h[g]+1;
		}
	}
	return 0;
}
