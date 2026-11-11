#include <bits/stdc++.h>
using namespace std;
char a[200005];
long long x[200005];
int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n,s=0,i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
        scanf("%lld %c",&x[i],&a[i]);
    for(i=1,j=n;i<j;){
        if(a[i]==a[j]){
            if(x[i]<x[j])x[j]-=x[i],++i;
            else if(x[j]<x[i])x[i]-=x[j],j--;
            else i++,j--;
            continue;
        }
        s+=min(x[j],x[i]);
        if(x[i]<x[j])x[j]-=x[i],++i;
        else if(x[j]<x[i])x[i]-=x[j],j--;
        else i++,j--;
    }
    printf("%lld",s);
	return 0;
}
