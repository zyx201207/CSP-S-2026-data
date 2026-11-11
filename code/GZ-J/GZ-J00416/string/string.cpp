//GZ-J00416 代正维 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200015],i,x,s,j,ans,l,r;
char c[200015],cyy[1000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
    	scanf("%lld %c",&a[i],&c[i]);
    	x=x+a[i];
	}
	for(i=1;i<=n;i++){
		for(j=0;j<a[i];j++){
			cyy[s]=c[i];
			s++;
		}
	}
	l=x-1;
	while(l!=r){
		if(cyy[l]!=cyy[r]){
			ans++;
		}
		l--;
		r++;
	}
	printf("%lld",ans);
	return 0;
} 
