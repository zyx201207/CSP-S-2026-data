#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long c[N];
char x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int len=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%lld %s",&c[i],&x[i]);
		len+=c[i];
		if(x[i]!=x[i-1])
			flag=false;
	}
	if(flag||n==1){
		printf("0");
		return 0;
	}
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=c[i];
		if(sum>=(len/2+(len%2))){
			for(int j=1;j<=i;j++){
				if(x[j]!=x[n+1-j]){
					ans+=c[j];
				}
			}
			if(c[i]-(sum-(len/2+(len%2)))!=(sum-(len/2+(len%2))))
				ans+=abs((c[i]-(sum-(len/2+(len%2))))-(sum-(len/2+(len%2))));
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
